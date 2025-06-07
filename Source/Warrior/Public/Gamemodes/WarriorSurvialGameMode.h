﻿// Valerii Diachenko All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseGameMode.h"
#include "WarriorSurvialGameMode.generated.h"

class AWarriorEnemyCharacter;

UENUM(BlueprintType)
enum class EWarriorSurvialGameModeState : uint8
{
    None,
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

    bool HasFinishedAllWaves() const;

    void PreLoadNextWaveEnemies();
    
    FWarriorEnemyWaveSpawnerTableRow* GetCurrentWaveSpawnerTableRow() const;

    int32 TrySpawnWaveEnemies();

    bool ShouldKeepSpawnEnemies() const;

    UFUNCTION()
    void OnEnemyDestroyed(AActor* DestroyedActor);
    
    UPROPERTY()
    EWarriorSurvialGameModeState CurrentSurvialGameModeState;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnSurvialGameModeStateChangedDelegate OnSurvialGameModeStateChanged;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    UDataTable* EnemyWaveSpawnerDataTable;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    int32 TotalWavesToSpawn;

    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    int32 CurrentWaveCount = 1;

    UPROPERTY(Transient)
    int32 CurrentSpawnedEnemiesCounter = 0;

    UPROPERTY(Transient)
    int32 TotalSpawnedEnemiesThisWaveCounter = 0;

    UPROPERTY(Transient)
    TArray<AActor*> TargetPointsArray;
    
    UPROPERTY()
    float TimePassedSinceStart = 0.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    float SpawnNewWaveWaitTime = 5.f;

    UPROPERTY(Transient)
    TMap<TSoftClassPtr<AWarriorEnemyCharacter>, UClass*> PreLoadedEnemyClassMap;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    float SpawnEnemiesDelayTime = 2.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WaveDefinition", meta = (AllowPrivateAccess = "true"))
    float WaveCompletedWaitTime = 5.f;
};
