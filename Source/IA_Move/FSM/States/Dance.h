// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IA_Move/FSM/TC_State.h"
#include "Dance.generated.h"

UCLASS()
class IA_MOVE_API UDance : public UTC_State
{
	GENERATED_BODY()
public:
	void OnEnterState() override;
	void OnExitState() override;
private:
	FTimerHandle TimerAnim;
	void DanceTimer();
	void OnNextTarget();
};
