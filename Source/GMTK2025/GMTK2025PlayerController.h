// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GMTK2025PlayerController.generated.h"

class UGameplayEffect;
class UNiagaraSystem;
class UGameplayAbility;
class UInputAction;
struct FInputActionValue;
class AGMTK2025Character;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWeaponConfig : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ConfigId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* UiIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 3000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMesh> ProjectileMesh = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TObjectPtr<UNiagaraSystem> AttachedNiagaraSystem = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TObjectPtr<UNiagaraSystem> ImpactParticle = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TSubclassOf<UGameplayEffect> HitGameplayEffect = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	float CooldownDuration = 0.5f;



};

/**
 *  Simple first person Player Controller
 *  Manages the input mapping context.
 *  Overrides the Player Camera Manager class.
 */
UCLASS(abstract)
class GMTK2025_API AGMTK2025PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	AGMTK2025PlayerController();

	// A cast reference to the player character, set on BeginPlay
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "References")
	TObjectPtr<AGMTK2025Character> PlayerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TSubclassOf<UGameplayAbility> ShootingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	FWeaponConfig CurrentWeaponConfig = FWeaponConfig();

	UFUNCTION(BlueprintCallable, Category = "Input")
	FHitResult GetActorUnderMouseCursor();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void UpdateWeaponConfig(FWeaponConfig NewWeaponConfig);

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input", meta = (AllowPrivateAccess = "true"))
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Called from Input Actions for movement input */
	void MoveInput(const FInputActionValue& Value);

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void Shoot();



	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Input")
	UInputAction* ShootAction;
	
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:

	void SetReferences();
	
	// Start twin stick movement
	FRotator LastRotation;
	void RotateCharacterToMouseCursor();
	// End twin stick movement
};
