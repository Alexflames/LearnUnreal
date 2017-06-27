// Copyright Foamy Sea 2017

#pragma once

#include "Components/ActorComponent.h"
#include "PushActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UPushActor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPushActor();

	void PushActor();

	FVector GetPlayerLocation();
	FVector GetPlayerNewLocation(FVector PlayerViewPointLocation);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	AActor* Owner;

	UPROPERTY(EditAnywhere)
	float SpeedMultiplier = 3.f;

	float Speed;
	float LastTriggerTime;
	float TimeSpent;

	UPROPERTY(EditAnywhere)
	float FlyDuration = 2.f;

	bool IsActorPushed = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Any)
	ATriggerVolume* CuteAnimalTrigger;
};
