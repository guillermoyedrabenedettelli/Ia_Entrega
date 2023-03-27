// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/TC_DamageableInterfaces.h"
#include "TC_Torret.generated.h"
class UStaticMeshComponent;
UCLASS()
class IA_MOVE_API ATC_Torret : public AActor, public ITC_DamageableInterfaces
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* StaticMeshComponent = nullptr;
	ATC_Torret();


};
