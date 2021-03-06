// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* getAITank() const;
	void BeginPlay() override;
	void Tick(float) override;
public:
	ATank* GetPlayerTank() const;


	
	
};
