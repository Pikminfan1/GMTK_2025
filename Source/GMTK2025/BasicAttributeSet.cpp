// Fill out your copyright notice in the Description page of Project Settings.

/////////////////
///DEPRECATED////
/////////////////


#include "BasicAttributeSet.h"
#include "GameplayEffectExtension.h"

//General Clamping
void UBasicAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	FString a = Attribute.AttributeName;

	//Health
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxHealth());
	}	
	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetHealth() > NewValue)
		{
			SetHealth(NewValue);
		}
	}
	
	//Stored Damage
	if (Attribute == GetStoredDamageAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxStoredDamage());
	}	
	if (Attribute == GetMaxStoredDamageAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetStoredDamage() > NewValue)
		{
			SetStoredDamage(NewValue);
		}
	}

	//Mana
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxMana());
	}
	if (Attribute == GetMaxManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetMana() > NewValue)
		{
			SetMana(NewValue);
		}
	}

	//Barrier
	if (Attribute == GetBarrierAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxBarrier());
	}
	if (Attribute == GetMaxBarrierAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetBarrier() > NewValue)
		{
			SetBarrier(NewValue);
		}
	}

	//Armor
	if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxArmor());
	}
	if (Attribute == GetMaxArmorAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetArmor() > NewValue)
		{
			SetArmor(NewValue);
		}
	}

	//Regen
	if (Attribute == GetManaRegenAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxRegen());
	}
	if (Attribute == GetHealthRegenAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxRegen());
	}
	if (Attribute == GetMaxRegenAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetManaRegen() > NewValue)
		{
			SetManaRegen(NewValue);
		}
		if (GetHealthRegen() > NewValue)
		{
			SetHealthRegen(NewValue);
		}
	}

	//Poise
	if (Attribute == GetPoiseAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, GetMaxPoise());
	}
	if (Attribute == GetMaxPoiseAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, NewValue);
		if (GetPoise() > NewValue)
		{
			SetPoise(NewValue);
		}
	}


	Super::PreAttributeChange(Attribute, NewValue);
}

void UBasicAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	//Health
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp<float>(GetHealth(), 0.0f, GetMaxHealth()));
	}

	//Mana
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp<float>(GetMana(), 0.0f, GetMaxMana()));
	}

	//Stored Damage
	if (Data.EvaluatedData.Attribute == GetStoredDamageAttribute())
	{
		SetStoredDamage(FMath::Clamp<float>(GetStoredDamage(), 0.0f, GetMaxStoredDamage()));
	}

	//Armor
	if (Data.EvaluatedData.Attribute == GetArmorAttribute())
	{
	    SetArmor(FMath::Clamp<float>(GetArmor(), 0.0f, GetMaxArmor()));
	}

	//Regen
	if (Data.EvaluatedData.Attribute == GetHealthRegenAttribute())
	{
		SetHealthRegen(FMath::Clamp<float>(GetHealthRegen(), 0.0f, GetMaxRegen()));	
	}

	if (Data.EvaluatedData.Attribute == GetManaRegenAttribute())
	{
		SetManaRegen(FMath::Clamp<float>(GetManaRegen(), 0.0f, GetMaxRegen()));
	}

	//Poise
	if (Data.EvaluatedData.Attribute == GetPoiseAttribute())
	{
		SetPoise(FMath::Clamp<float>(GetPoise(), 0.0f, GetMaxPoise()));
	}

	//Barrier
	if (Data.EvaluatedData.Attribute == GetBarrierAttribute())
	{
		SetBarrier(FMath::Clamp<float>(GetBarrier(), 0.0f, GetMaxBarrier()));
	}

	

}

