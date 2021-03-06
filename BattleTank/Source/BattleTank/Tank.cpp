// Fill out your copyright notice in the Description page of Project Settings.
//#include "TankBarrel.h"
#include "BattleTank.h"
#include "TankTurrent.h"
#include "TankAimingComponet.h"
#include "Tank.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponet = CreateDefaultSubobject<UTankAimingComponet>(FName("Aiming Componet"));

}

void ATank::SetBarrelRefernce(UTankBarrel* Barrelref) {
	TankAimingComponet->SetBarrelRefrence(Barrelref);
}

void ATank::SetTurrentRefernce(UTankTurrent* TurrentRefernce) {
	TankAimingComponet->SetTurrentRefernce(TurrentRefernce);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector Hitlocation) {
	TankAimingComponet->AimAt(Hitlocation, LaunchSpeed);
	
	
}

void ATank :: Fire() {
	UE_LOG(LogTemp, Warning, TEXT("Firing....") );
}