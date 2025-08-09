// Copyright Epic Games, Inc. All Rights Reserved.


#include "GMTK2025PlayerController.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "GMTK2025CameraManager.h"
#include "GMTK2025Character.h"

AGMTK2025PlayerController::AGMTK2025PlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AGMTK2025CameraManager::StaticClass();
}

void AGMTK2025PlayerController::MoveInput(const FInputActionValue& Value)
{
	// get the Vector2D move axis
	FVector2D MovementVector = Value.Get<FVector2D>();

	// pass the axis values to the move input
	DoMove(MovementVector.X, MovementVector.Y);
}

void AGMTK2025PlayerController::DoMove(float Right, float Forward)
{
	if (!PlayerCharacter || !PlayerCameraManager) return;
	
	const FRotator CameraRotation = PlayerCameraManager->GetCameraRotation();
	const FRotator YawRotation(0.f, CameraRotation.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	PlayerCharacter->AddMovementInput(ForwardDirection, Forward);
	PlayerCharacter->AddMovementInput(RightDirection, Right);
}

// Make sure to set ShootingAbility in the PlayerController
void AGMTK2025PlayerController::Shoot()
{
	if (ShootingAbility)
	{
		PlayerCharacter->GetAbilitySystemComponent()->TryActivateAbilityByClass(ShootingAbility);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("No shooting ability has been set in the Player Controller. Ability not fired"));
	}
	
}

void AGMTK2025PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::MoveInput);

		// Shooting
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &ThisClass::Shoot);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AGMTK2025PlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetReferences();
}

void AGMTK2025PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateCharacterToMouseCursor();
}

void AGMTK2025PlayerController::SetReferences()
{
	PlayerCharacter = Cast<AGMTK2025Character>(GetCharacter());
}

FHitResult AGMTK2025PlayerController::GetActorUnderMouseCursor()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return CursorHit;

	//DrawDebugSphere(GetWorld(), CursorHit.ImpactPoint, 50.f, 12, FColor::Red);

	return CursorHit;
}

void AGMTK2025PlayerController::UpdateWeaponConfig(FWeaponConfig NewWeaponConfig)
{
	CurrentWeaponConfig = NewWeaponConfig;
}

void AGMTK2025PlayerController::RotateCharacterToMouseCursor()
{
	if (!PlayerCharacter) return;
	
	FHitResult HitResult = GetActorUnderMouseCursor();
	if (HitResult.bBlockingHit)
	{
		FVector PlayerLocation = PlayerCharacter->GetActorLocation();
		FVector HitActorLocation = HitResult.ImpactPoint;
		FVector TargetDirection = (HitActorLocation - PlayerLocation).GetSafeNormal();
		FRotator Rotation = TargetDirection.Rotation();
		LastRotation = Rotation;
	}
	PlayerCharacter->GetMesh()->SetWorldRotation(FRotator(0, LastRotation.Yaw - 90.0f, 0));
}
