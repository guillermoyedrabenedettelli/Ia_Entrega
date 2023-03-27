// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ia_Move/FSM/TC_State.h"
#include "TC_Pray.generated.h"


UCLASS()
class IA_MOVE_API UTC_Pray : public UTC_State
{
	GENERATED_BODY()
public:
		void OnEnterState() override;
		void OnExitState() override;
private:
	FTimerHandle TimerAnim;
	void OnPrayTimer();
	void OnNextTarget();
};
