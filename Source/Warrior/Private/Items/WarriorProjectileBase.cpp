﻿// Valerii Diachenko All Rights Reserved.


#include "WarriorProjectileBase.h"

#include "NiagaraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "WarriorDebugHelper.h"


AWarriorProjectileBase::AWarriorProjectileBase()
{
    PrimaryActorTick.bCanEverTick = false;

    ProjectileCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ProjectileCollisionBox"));
    SetRootComponent(ProjectileCollisionBox);

    ProjectileCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
    ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
    ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
    ProjectileCollisionBox->OnComponentHit.AddUniqueDynamic(this, &ThisClass::OnProjectileHit);
    ProjectileCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnProjectileBeginOverlap);

    ProjectileNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ProjectileNiagaraComponent"));
    ProjectileNiagaraComponent->SetupAttachment(GetRootComponent());

    ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
    ProjectileMovementComp->InitialSpeed = 700.f;
    ProjectileMovementComp->MaxSpeed = 900.f;
    ProjectileMovementComp->Velocity = FVector(1.f,0.f,0.f);
    ProjectileMovementComp->ProjectileGravityScale = 0.f;

    InitialLifeSpan = 4.f;
}

void AWarriorProjectileBase::BeginPlay()
{
    Super::BeginPlay();

    if (ProjectileDamagePolicy == EProjectileDamagePolicy::OnBeginOverlap)
    {
        ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
    }
}

void AWarriorProjectileBase::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor)
    {
        Debug::Print(OtherActor->GetActorNameOrLabel());

        Destroy();
    }
}
void AWarriorProjectileBase::OnProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}