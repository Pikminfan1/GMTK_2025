// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GMTK2025_API UBasicAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	//Health
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxHealth);

	//Mana
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Mana)
		
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxMana);

	//Barrier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Barrier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Barrier);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxBarrier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxBarrier);
	
	//Poise
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Poise;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Poise);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxPoise;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxPoise);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AdditionalPoise;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, AdditionalPoise);

	//Armor
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Armor);
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxArmor;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxArmor);

	//Stagger
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData StaggerThreshold;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, StaggerThreshold);
	
	//Pierce Protection
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData PierceProtection;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, PierceProtection);
	
	//Damage Multiplier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DamageMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, DamageMultiplier);
	
	//Defense Multiplier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData DefenseMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, DefenseMultiplier);

	//Impact Multiplier
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ImpactMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, ImpactMultiplier);

	//Regen
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, ManaRegen);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxRegen;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxRegen);

	//Speed
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, AttackSpeed);
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MovementSpeed);

	//Cooldown
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CooldownMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, CooldownMultiplier);

	//Cost
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData SpellCostMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, SpellCostMultiplier);

	//Effect Duration
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData EffectDurationMultiplier;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, EffectDurationMultiplier);

	//Perception
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Perception;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, Perception);

	//Stored Damage
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData StoredDamage;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, StoredDamage);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxStoredDamage;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxStoredDamage);

	//Aggro
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData CurrentAggro;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, CurrentAggro);
	
	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData MaxAggro;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, MaxAggro);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData AppliedAggro;
	ATTRIBUTE_ACCESSORS(UBasicAttributeSet, AppliedAggro);
	

protected:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
