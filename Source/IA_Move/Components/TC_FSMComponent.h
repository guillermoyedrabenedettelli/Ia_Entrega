// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TC_FSMComponent.generated.h"

class UTC_State;

UENUM(BlueprintType)
enum class Estate : uint8
{
	GoToTarget,
	AttackTarget
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IA_MOVE_API UTC_FSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditDefaultsOnly, Category = "FSN")
		TMap<Estate, TSoftClassPtr<UTC_State>> States;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ChangeState(Estate NewState);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	
private:
	TWeakObjectPtr<UTC_State> CurrentState = nullptr;
};
