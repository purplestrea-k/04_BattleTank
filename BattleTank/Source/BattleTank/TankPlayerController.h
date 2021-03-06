// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
 public:
	 ATank* GetControlledTank() const;

	 void BeginPlay() override;

	 void Tick(float) override;
 
private:
      //Moves the tank barrel so that a shot would hit where the crosshair interesects the world.
	UPROPERTY(EditAnywhere)
	 float crossHairXlocation=0.5;

	UPROPERTY(EditAnywhere)
	float crossHairYlocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000000.00; //Defaul 10km

	//FVector2D ScreenLocation;

	 void AimtowardsCrosshairs();
	 bool GetSightRayHitLocation(FVector&) const;
	 bool GetLookDirection(FVector2D, FVector&) const;
	 bool GetLookVectorHitLocation(FVector,FVector&) const;
	
};
