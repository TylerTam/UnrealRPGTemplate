// Fill out your copyright notice in the Description page of Project Settings.


#include "TPS_BaseCharacter.h"

// Sets default values
ATPS_BaseCharacter::ATPS_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATPS_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATPS_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATPS_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAISense_Sight::EVisibilityResult ATPS_BaseCharacter::CanBeSeenFrom(const FCanBeSeenFromContext& Context, FVector& OutSeenLocation, int32& OutNumberOfLoSChecksPerformed, int32& OutNumberOfAsyncLosCheckRequested, float& OutSightStrength, int32* UserData, const FOnPendingVisibilityQueryProcessedDelegate* Delegate)
{	
	FHitResult res;
	FVector boneLocation = GetMesh()->GetSocketLocation("head");
	FCollisionQueryParams traceParams;

	const FName TraceTag = FName("SenseTrace");
	traceParams.TraceTag = TraceTag;

	bool hit = GetWorld()->LineTraceSingleByChannel(res, Context.ObserverLocation, boneLocation, ECC_GameTraceChannel3, traceParams);// FCollisionObjectQueryParams::DefaultObjectQueryParam,
	//DrawDebugLine(GetWorld(), Context.ObserverLocation, boneLocation, FColor(0, 255, 0), false, -1, 0, 12.333);
	//GetWorld()->DebugDrawTraceTag = TraceTag;
	if (!hit) {
		OutSeenLocation = boneLocation;
		OutSightStrength = 1;
		return UAISense_Sight::EVisibilityResult::Visible;
	}

	boneLocation = GetMesh()->GetSocketLocation("spine_05");
	hit = GetWorld()->LineTraceSingleByChannel(res, Context.ObserverLocation, boneLocation, ECC_GameTraceChannel3, traceParams);// FCollisionObjectQueryParams::DefaultObjectQueryParam,
	//DrawDebugLine(GetWorld(), Context.ObserverLocation, boneLocation, FColor(0, 255, 0), false, -1, 0, 12.333);

	if (!hit) {
		OutSeenLocation = boneLocation;
		OutSightStrength = 1;
		return UAISense_Sight::EVisibilityResult::Visible;
	}

	boneLocation = GetActorLocation();
	hit = GetWorld()->LineTraceSingleByChannel(res, Context.ObserverLocation, boneLocation, ECC_GameTraceChannel3, traceParams);// FCollisionObjectQueryParams::DefaultObjectQueryParam,
	//DrawDebugLine(GetWorld(), Context.ObserverLocation, boneLocation, FColor(255, 0, 0), false, -1, 0, 12.333);
	if (!hit) {
		OutSeenLocation = boneLocation;
		OutSightStrength = 1;

		return UAISense_Sight::EVisibilityResult::Visible;
	}
	
	OutSightStrength = 0;
	return UAISense_Sight::EVisibilityResult::NotVisible;


	//UAISense_Sight::EVisibilityResult::Visible : UAISense_Sight::EVisibilityResult::NotVisible;
}

