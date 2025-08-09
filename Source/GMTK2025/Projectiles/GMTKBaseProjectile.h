// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GMTKBaseProjectile.generated.h"

class UGameplayEffect;
class UNiagaraSystem;
class UNiagaraComponent;
class UProjectileMovementComponent;

UCLASS()
class GMTK2025_API AGMTKBaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AGMTKBaseProjectile();

/*
 * Variables
 */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TObjectPtr<UNiagaraComponent> NiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ExposeOnSpawn))
	TObjectPtr<UNiagaraSystem> ImpactParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ExposeOnSpawn))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ExposeOnSpawn))
	TSubclassOf<UGameplayEffect> HitGameplayEffect;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn))
	TObjectPtr<AActor> ProjectileOwner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ExposeOnSpawn))
	float Damage;
/*
 * Methods
 */
	UFUNCTION(BlueprintNativeEvent)
	void OnProjectileHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

protected:
	virtual void BeginPlay() override;

};
