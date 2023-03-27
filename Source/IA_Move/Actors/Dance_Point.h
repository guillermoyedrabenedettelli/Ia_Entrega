// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dance_Point.generated.h"
class UStaticMeshComponent;
UCLASS()
class IA_MOVE_API ADance_Point : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADance_Point();
	// Called every frame
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;
	

};
