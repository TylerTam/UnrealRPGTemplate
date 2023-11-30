// Fill out your copyright notice in the Description page of Project Settings.

#include "TPS_AiController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig.h"



void ATPS_AiController::ChangeAiSightDistances(float seeRadius, float loseRadius)
{

	
	/*
	FAISenseID Id = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	
	if (!Id.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Wrong Sense ID"));
		return;
	}

	
	UAIPerceptionComponent* perceptionComp = GetPerceptionComponent();
	UAISenseConfig* conf = perceptionComp->GetSenseConfig(Id);

	if (conf == nullptr)
		return;

	UAISenseConfig_Sight* ConfigSight = Cast<UAISenseConfig_Sight>(conf);*/
	///////////////////////////////////////
	// 
	// 
	// 
	// 
	// 
	///

	//// Save original lose range
	//float LoseRange = ConfigSight->LoseSightRadius - ConfigSight->SightRadius;


	//ConfigSight->SightRadius = seeRadius;

	//// Apply lose range to new radius of the sight
	//ConfigSight->LoseSightRadius = loseRadius;

	//GetPerception()->RequestStimuliListenerUpdate();
}
