// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TC_MinionCharacter.generated.h"
class USphereComponent;
UCLASS()
class IA_MOVE_API ATC_MinionCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		USphereComponent* sphereComponent = nullptr;
	ATC_MinionCharacter();
	


protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnSphereOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
