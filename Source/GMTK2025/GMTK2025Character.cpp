// Copyright Epic Games, Inc. All Rights Reserved.

#include "GMTK2025Character.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.h"
#include "GMTK2025PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "GAS/GMTKAbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AGMTK2025Character

void AGMTK2025Character::AddStartupAbilities()
{
	for (TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

AGMTK2025Character::AGMTK2025Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	// Create the first person mesh that will be viewed only by this character's owner
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));

	FirstPersonMesh->SetupAttachment(GetMesh());
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(GetRootComponent());

	// Create the Camera Component	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("First Person Camera"));
	FirstPersonCameraComponent->SetupAttachment(SpringArm);

	//GAS
	AbilitySystemComponent = CreateDefaultSubobject<UGMTKAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AGMTK2025Character::BeginPlay()
{
	if (IsValid(AbilitySystemComponent))
	{
		BasicAttributeSet = AbilitySystemComponent->GetSet<UBasicAttributeSet>();
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetHealthAttribute()).AddUObject(this, &AGMTK2025Character::OnHealthAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetManaAttribute()).AddUObject(this, &AGMTK2025Character::OnManaAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetBarrierAttribute()).AddUObject(this, &AGMTK2025Character::OnBarrierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetPoiseAttribute()).AddUObject(this, &AGMTK2025Character::OnPoiseAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetAdditionalPoiseAttribute()).AddUObject(this, &AGMTK2025Character::OnAdditionalPoiseAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetArmorAttribute()).AddUObject(this, &AGMTK2025Character::OnArmorAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetHealthRegenAttribute()).AddUObject(this, &AGMTK2025Character::OnHealthRegenAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetMovementSpeedAttribute()).AddUObject(this, &AGMTK2025Character::OnMovementSpeedAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetSpellCostMultiplierAttribute()).AddUObject(this, &AGMTK2025Character::OnSpellCostMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetDamageMultiplierAttribute()).AddUObject(this, &AGMTK2025Character::OnDamageMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetImpactMultiplierAttribute()).AddUObject(this, &AGMTK2025Character::OnImpactMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetCooldownMultiplierAttribute()).AddUObject(this, &AGMTK2025Character::OnCooldownMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetAttackSpeedAttribute()).AddUObject(this, &AGMTK2025Character::OnAttackSpeedAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetStoredDamageAttribute()).AddUObject(this, &AGMTK2025Character::OnStoredDamageAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetEffectDurationMultiplierAttribute()).AddUObject(this, &AGMTK2025Character::OnEffectDurationMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetPerceptionAttribute()).AddUObject(this, &AGMTK2025Character::OnPerceptionAttributeChanged);
	}

	Super::BeginPlay();

	SetReferences();
	AddStartupAbilities();
}

void AGMTK2025Character::SetReferences()
{
	GMTKPlayerController = Cast<AGMTK2025PlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}

#pragma region
void AGMTK2025Character::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnManaAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnBarrierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnBarrierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnPoiseAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnPoiseChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnAdditionalPoiseAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAdditionalPoiseChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnArmorAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnArmorChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnHealthRegenAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthRegenChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnMovementSpeedAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnMovementSpeedChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnSpellCostMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnSpellCostMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnDamageMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnDamageMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnImpactMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnImpactMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnCooldownMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnCooldownMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnAttackSpeedAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAttackSpeedChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnStoredDamageAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnStoredDamageChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnEffectDurationMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnEffectDurationMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AGMTK2025Character::OnPerceptionAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnPerceptionChanged(Data.OldValue, Data.NewValue);
}

#pragma endregion


