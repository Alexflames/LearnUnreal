// Copyright Foamy Sea 2017

#include "EscapeRoom.h"
#include "trial_two_mine_explosion.h"

#define OUT

// Sets default values for this component's properties
Utrial_two_mine_explosion::Utrial_two_mine_explosion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void Utrial_two_mine_explosion::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("Pressure plate has no owner"));
	}
	else {
		Owner = GetOwner();
	}
	
}

// Called every frame
void Utrial_two_mine_explosion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PressurePlate) { return; }

	if (CheckIfPlayerEntered()) {
		UE_LOG(LogTemp, Warning, TEXT("%s is going to explode!"), *GetOwner()->GetName());
		OnEnter.Broadcast();
		IfTriggered = true;
	}
	else if (!IfTriggered)
		Waiting.Broadcast();
}

bool Utrial_two_mine_explosion::CheckIfPlayerEntered()
{
	if (!PressurePlate) { return false; }
	
	// Get actors on plate
	TArray <AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);

	for (auto& Actor : OverlappingActors) {
		if (Actor->ActorHasTag("Player"))
			return true;
	}
	return false;
}
