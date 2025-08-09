// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "Characters/GMTKCharacterBase.h"
#include "Logging/LogMacros.h"
#include "GMTK2025Character.generated.h"

class AGMTK2025PlayerController;
class UGameplayEffect;
class USpringArmComponent;
class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A basic first person character
 */
UCLASS(abstract)
class AGMTK2025Character : public AGMTKCharacterBase
{
	GENERATED_BODY()

public:

/*
 * Variables
 */

	/** Pawn mesh: first person view (arms; seen only by self) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	USkeletalMeshComponent* FirstPersonMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<USpringArmComponent> SpringArm;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<AGMTK2025PlayerController> GMTKPlayerController;

/*
 * Methods
 */
	
	UFUNCTION(BlueprintCallable, Category="Abilities")
	void AddStartupAbilities();

public:
	AGMTK2025Character();

protected:

	virtual void BeginPlay() override;

	//On attribute Changed Events
#pragma region
//Health OnChanged
	virtual void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthChanged(float oldValue, float NewValue);
	//

	//Mana OnChanged
	virtual void OnManaAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnManaChanged(float oldValue, float NewValue);
	//

	//Barrier OnChanged
	virtual void OnBarrierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnBarrierChanged(float oldValue, float NewValue);
	//

	//Poise OnChange
	virtual void OnPoiseAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnPoiseChanged(float oldValue, float NewValue);


	virtual void OnAdditionalPoiseAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnAdditionalPoiseChanged(float oldValue, float NewValue);
	//

	//Armor OnChange
	virtual void OnArmorAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnArmorChanged(float oldValue, float NewValue);
	//

	//Regen OnChange
	virtual void OnHealthRegenAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnHealthRegenChanged(float oldValue, float NewValue);
	//

	//MovementSpeed OnChange
	virtual void OnMovementSpeedAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnMovementSpeedChanged(float oldValue, float NewValue);
	//

	//CostMultiplier OnChange
	virtual void OnSpellCostMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnSpellCostMultiplierChanged(float oldValue, float NewValue);
	//

	//DamageMultiplier OnChange
	virtual void OnDamageMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnDamageMultiplierChanged(float oldValue, float NewValue);
	//

	//ImpactMultiplier OnChange
	virtual void OnImpactMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnImpactMultiplierChanged(float oldValue, float NewValue);
	//

	//CooldownMultiplier OnChange
	virtual void OnCooldownMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnCooldownMultiplierChanged(float oldValue, float NewValue);
	//

	//AttackSpeed OnChange
	virtual void OnAttackSpeedAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnAttackSpeedChanged(float oldValue, float NewValue);
	//

	//StoredDamage OnChange
	virtual void OnStoredDamageAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnStoredDamageChanged(float oldValue, float NewValue);
	//

	//EffectDurationMultiplier OnChange
	virtual void OnEffectDurationMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnEffectDurationMultiplierChanged(float oldValue, float NewValue);
	//

	//Perception OnChange
	virtual void OnPerceptionAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnPerceptionChanged(float oldValue, float NewValue);
	//
#pragma endregion

public:

	/** Returns the first person mesh **/
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Returns first person camera component **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

private:
	void SetReferences();

};

