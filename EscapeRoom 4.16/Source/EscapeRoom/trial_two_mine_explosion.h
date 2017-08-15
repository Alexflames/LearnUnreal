// Copyright Foamy Sea 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "trial_two_mine_explosion.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMineEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API Utrial_two_mine_explosion : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	Utrial_two_mine_explosion();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FMineEvent OnEnter;

	UPROPERTY(BlueprintAssignable)
	FMineEvent Waiting;

private:
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;
		
	AActor* Owner;

	// Check if player overlaps the trigger volume
	bool CheckIfPlayerEntered();
	bool IfTriggered = false;
};
