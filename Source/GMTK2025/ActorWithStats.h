// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffectTypes.h"
#include "ActorWithStats.generated.h"

UCLASS()
class GMTK2025_API AActorWithStats : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorWithStats();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	const class UBasicAttributeSet* BasicAttributeSet;

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

	//CostMultiplier OnChange
	virtual void OnSpellCostMultiplierAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "GAS")
	void OnSpellCostMultiplierChanged(float oldValue, float NewValue);
	//

	//Damageultiplier OnChange
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
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
