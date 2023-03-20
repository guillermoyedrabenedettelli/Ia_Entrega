// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_SpawnPoint.h"
#include "../Controllers/TC_MinionController.h"
#include "../Characters/TC_MinionCharacter.h"

// Sets default values
ATC_SpawnPoint::ATC_SpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATC_SpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	SpawnMinion();
	//GetWorldTimerManager().SetTimer(SpawnTimer,this, &ATC_SpawnPoint::SpawnMinion,10.f,true);
}

void ATC_SpawnPoint::SpawnMinion()
{
	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ATC_MinionCharacter* SpawnedMinion = GetWorld()->SpawnActor<ATC_MinionCharacter>(ClassToSpawn, GetActorTransform(),Params);
	if (!SpawnedMinion) {
		UE_LOG(LogTemp,Error,TEXT("ATC_SpawnPoint::SpawnMinion Couldn't spawn a minion"));
	}
	SpawnedMinion->SpawnDefaultController();
	ATC_MinionController* MinionController = Cast<ATC_MinionController>(SpawnedMinion->GetController());
	if (MinionController) {
		MinionController->SetTarget(Target);
		MinionController->InitFSM();
	}
}


