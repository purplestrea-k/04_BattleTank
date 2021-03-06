// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankBarrel.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponet.generated.h"

class UTankBarrel;
class UTankTurrent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponet();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector WorldspaceAim, float LaunchSpeed);

	void SetBarrelRefrence(UTankBarrel*);

	void SetTurrentRefernce(UTankTurrent*);
	

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurrent* Turrent = nullptr;

	void MoveBarrel(FVector AimDirection);
	void MoveTurrent(FVector AimDirection);
};
