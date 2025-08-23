// Fill out your copyright notice in the Description page of Project Settings.

/////////////////
///DEPRECATED////
/////////////////


#include "ActorWithStats.h"
#include "AbilitySystemComponent.h"
#include "BasicAttributeSet.h"

// Sets default values
AActorWithStats::AActorWithStats()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

}

// Called when the game starts or when spawned
void AActorWithStats::BeginPlay()
{
	if (IsValid(AbilitySystemComponent))
	{
		BasicAttributeSet = AbilitySystemComponent->GetSet<UBasicAttributeSet>();
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetHealthAttribute()).AddUObject(this, &AActorWithStats::OnHealthAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetManaAttribute()).AddUObject(this, &AActorWithStats::OnManaAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetBarrierAttribute()).AddUObject(this, &AActorWithStats::OnBarrierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetPoiseAttribute()).AddUObject(this, &AActorWithStats::OnPoiseAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetAdditionalPoiseAttribute()).AddUObject(this, &AActorWithStats::OnAdditionalPoiseAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetArmorAttribute()).AddUObject(this, &AActorWithStats::OnArmorAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetHealthRegenAttribute()).AddUObject(this, &AActorWithStats::OnHealthRegenAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetSpellCostMultiplierAttribute()).AddUObject(this, &AActorWithStats::OnSpellCostMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetDamageMultiplierAttribute()).AddUObject(this, &AActorWithStats::OnDamageMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetImpactMultiplierAttribute()).AddUObject(this, &AActorWithStats::OnImpactMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetCooldownMultiplierAttribute()).AddUObject(this, &AActorWithStats::OnCooldownMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetAttackSpeedAttribute()).AddUObject(this, &AActorWithStats::OnAttackSpeedAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetStoredDamageAttribute()).AddUObject(this, &AActorWithStats::OnStoredDamageAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetEffectDurationMultiplierAttribute()).AddUObject(this, &AActorWithStats::OnEffectDurationMultiplierAttributeChanged);
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BasicAttributeSet->GetPerceptionAttribute()).AddUObject(this, &AActorWithStats::OnPerceptionAttributeChanged);
		//AbilitySystemComponent->RefreshAbilityActorInfo();
	}
	
	Super::BeginPlay();
	
}

void AActorWithStats::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnManaAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnBarrierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnBarrierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnPoiseAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnPoiseChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnAdditionalPoiseAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAdditionalPoiseChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnArmorAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnArmorChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnHealthRegenAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthRegenChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnSpellCostMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnSpellCostMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnDamageMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnDamageMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnImpactMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnImpactMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnCooldownMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnCooldownMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnAttackSpeedAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAttackSpeedChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnStoredDamageAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnStoredDamageChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnEffectDurationMultiplierAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnEffectDurationMultiplierChanged(Data.OldValue, Data.NewValue);
}

void AActorWithStats::OnPerceptionAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnPerceptionChanged(Data.OldValue, Data.NewValue);
}

// Called every frame
void AActorWithStats::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

