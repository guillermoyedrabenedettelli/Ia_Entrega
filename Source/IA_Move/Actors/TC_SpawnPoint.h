// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TC_SpawnPoint.generated.h"
class ATC_MinionCharacter;
UCLASS()
class IA_MOVE_API ATC_SpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATC_MinionCharacter> ClassToSpawn;
	UPROPERTY(EditAnywhere)
		TArray<AActor*> Target;



	// Sets default values for this actor's properties
	ATC_SpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FTimerHandle SpawnTimer;
	
	void SpawnMinion();

};
