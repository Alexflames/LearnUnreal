// Copyright Foamy Sea 2017

#include "EscapeRoom.h"
#include "PushActor.h"


// Sets default values for this component's properties
UPushActor::UPushActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPushActor::BeginPlay()
{
	Super::BeginPlay();
	
	Owner = GetOwner();
	// ...
	
}


// Called every frame
void UPushActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if ((IsActorPushed == false && CuteAnimalTrigger->IsOverlappingActor(Owner)) || IsActorPushed == true) {
		/*
		if (CuteAnimalTrigger->IsOverlappingActor(Owner))
			LastTriggerTime = GetWorld()->GetTimeSeconds();
		PushActor();
		//UE_LOG(LogTemp, Warning, TEXT("Ready to push"));
		Owner->SetActorLocation(GetPlayerNewLocation(GetPlayerLocation()), false, NULL, ETeleportType::None);
		*/
	}
	
}

void UPushActor::PushActor()
{
	IsActorPushed = true;
	TimeSpent = GetWorld()->GetTimeSeconds();
	
	Speed = (FlyDuration + LastTriggerTime - TimeSpent) * SpeedMultiplier;

	if (FlyDuration + LastTriggerTime - TimeSpent < (FlyDuration / 10))
	{
		IsActorPushed = false;
	}
}

FVector UPushActor::GetPlayerLocation()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		PlayerViewPointLocation,
		PlayerViewPointRotation
	);
	return PlayerViewPointLocation;
}

FVector UPushActor::GetPlayerNewLocation(FVector PlayerViewPointLocation)
{
	PlayerViewPointLocation.Y += Speed;
	return PlayerViewPointLocation;
}


