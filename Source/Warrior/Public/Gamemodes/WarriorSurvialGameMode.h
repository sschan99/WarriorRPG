﻿// Valerii Diachenko All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseGameMode.h"
#include "WarriorSurvialGameMode.generated.h"

class AWarriorEnemyCharacter;

UENUM(BlueprintType)
enum class EWarriorSurvialGameModeState : uint8
{
    WaitSpawnNewWave,
    SpawningNewWave,
    InProgress,
    WaveCompleted,
    AllWavesDone,
    PlayerDied
};


USTRUCT(BlueprintType)
struct FWarriorEnemyWaveSpawnerInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    TSoftClassPtr<AWarriorEnemyCharacter> SoftEnemyClassToSpawn;
    
    UPROPERTY(EditAnywhere)
    int32 MinPerSpawnCount = 1;

    UPROPERTY(EditAnywhere)
    int32 MaxPerSpawnCount = 3;
};

USTRUCT(BlueprintType)
struct FWarriorEnemyWaveSpawnerTableRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    TArray<FWarriorEnemyWaveSpawnerInfo> EnemyWaveSpawnerDefinitions;

    UPROPERTY(EditAnywhere)
    int32 TotalEnemyToSpawnThisWave = 1;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSurvialGameModeStateChangedDelegate, EWarriorSurvialGameModeState, CurrentState);

/**
 * 
 */
UCLASS()
class WARRIOR_API AWarriorSurvialGameMode : public AWarriorBaseGameMode
{
    GENERATED_BODY()

protected:

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

private:

    void SetCurrentSurvialGameModeState(EWarriorSurvialGameModeState InState);

    UPROPERTY()
    EWarriorSurvialGameModeState CurrentSurvialGameModeState;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnSurvialGameModeStateChangedDelegate OnSurvialGameModeStateChanged;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    UDataTable* EnemyWaveSpawnerDataTable;
};
