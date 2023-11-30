// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig.h"
#include "TPS_AiController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_TEMPLATE_API ATPS_AiController : public AAIController
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = Ai)
		void ChangeAiSightDistances(float seeRadius, float loseRadius);
};
