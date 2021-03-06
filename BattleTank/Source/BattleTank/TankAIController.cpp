// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

ATank* ATankAIController::getAITank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {

Super::BeginPlay();

  auto ControlledTank = getAITank();
  auto PCTank = GetPlayerTank();


	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank"));
	}
	else
	UE_LOG(LogTemp, Warning, TEXT("Unfreindly Tank: %s"), *(ControlledTank->GetName()) );


	if (PCTank!= nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Player tank, %s , found by %s"), *(PCTank->GetName()), *(ControlledTank->GetName()) );
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank 404 error"));
	}
		


}

//Aims towards the player location per every tick.
void ATankAIController:: Tick(float Deltaseconds) {
	Super::Tick(Deltaseconds);
	//FVector HitLocation;
	if (GetPlayerTank()) {
		getAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}



ATank* ATankAIController::GetPlayerTank() const {

	auto playerController = GetWorld()->GetFirstPlayerController()->GetPawn();

		if (!playerController)
			return nullptr;
		else

		return Cast<ATank>(playerController);
}



