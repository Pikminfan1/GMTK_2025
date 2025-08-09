// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/GMTKAbilitySystemComponent.h"

void UGMTKAbilitySystemComponent::ApplyEffectToTarget(TSubclassOf<UGameplayEffect> Effect, float AmountToAdd, FName AttributeTag, UAbilitySystemComponent* TargetASC)
{
	FGameplayEffectContextHandle ContextHandle = MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(Effect, 1.0f, ContextHandle);
	SpecHandle.Data->SetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(AttributeTag), AmountToAdd);
	
	ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);
}
