// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles/GMTKBaseProjectile.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AGMTKBaseProjectile::AGMTKBaseProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 3000.0f;
	Damage = 10.f;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);

	NiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>("NiagaraSystem");
	NiagaraSystem->SetupAttachment(StaticMeshComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->bShouldBounce = false;
	ProjectileMovementComponent->InitialSpeed = Speed;
	ProjectileMovementComponent->MaxSpeed = Speed;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
}

void AGMTKBaseProjectile::OnProjectileHit_Implementation(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	/*if (ImpactParticle)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ImpactParticle, Hit.ImpactPoint);
	}

	if (NiagaraSystem)
	{
		NiagaraSystem->Deactivate();
	}

	StaticMeshComponent->SetHiddenInGame(true);

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle,
		[this]()
		{
			Destroy();
		},
		5.0f,
		false);*/

	// Make sure to bind to this in Blueprint so you can apply the correct effect - BP_BaseProjectile should already be bound
}

void AGMTKBaseProjectile::BeginPlay()
{
	Super::BeginPlay();

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnProjectileHit);
}

