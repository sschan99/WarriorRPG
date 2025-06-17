﻿// Valerii Diachenko All Rights Reserved.


#include "WarriorGameInstance.h"

TSoftObjectPtr<UWorld> UWarriorGameInstance::GetGameLevelByTag(FGameplayTag InTag)
{
    for (const FWarriorGameLevelSet& GameLevelSet : GameLevelSets)
    {
        if(!GameLevelSet.IsValid())
        {
            continue;
        }
        
        if (GameLevelSet.LevelTag == InTag)
        {
            return GameLevelSet.Level;
        }
    }
    
    return TSoftObjectPtr<UWorld>();
}