// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ia_Move/FSM/TC_State.h"
#include "TC_AttactTarget.generated.h"


UCLASS()
class IA_MOVE_API UTC_AttactTarget : public UTC_State
{
	GENERATED_BODY()
public:
		void OnEnterState() override;
		void OnExitState() override;
private:
	FTimerHandle AttackTimer;
	void OnAttackTimer();
	void OnNextTarget();
};
