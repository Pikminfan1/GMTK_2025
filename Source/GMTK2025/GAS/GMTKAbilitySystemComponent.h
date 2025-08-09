// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GMTKAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class GMTK2025_API UGMTKAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "GAS")
	void ApplyEffectToTarget(TSubclassOf<UGameplayEffect> Effect, float AmountToAdd, FName AttributeTag, UAbilitySystemComponent* TargetASC);
	
};
