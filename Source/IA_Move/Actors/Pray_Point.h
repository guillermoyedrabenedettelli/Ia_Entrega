// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pray_Point.generated.h"
class UStaticMeshComponent;
UCLASS()
class IA_MOVE_API APray_Point : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APray_Point();
	// Called every frame
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;
	

};
