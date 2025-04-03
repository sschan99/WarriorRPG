﻿// Valerii Diachenko All Rights Reserved.


#include "UI/EnemyUIComponent.h"
#include "Widgets/WarriorWidgetBase.h"

void UEnemyUIComponent::RegisterEnemyDrawnWidget(UWarriorWidgetBase* InWidgetToRegister)
{
    EnemyDrawnWidgets.Add(InWidgetToRegister);
}

void UEnemyUIComponent::RemoveEnemyDrawnWidgetsIfAny()
{
    if (EnemyDrawnWidgets.IsEmpty())
    {
        return;
    }
    
    for (UWarriorWidgetBase* DrawnWidget : EnemyDrawnWidgets)
    {
        if (DrawnWidget)
        {
            DrawnWidget->RemoveFromParent();
        }
    }
}