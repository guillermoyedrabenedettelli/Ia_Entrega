// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_MinionController.h"

ATC_MinionController::ATC_MinionController() : Super()
{
	FSMComponent = CreateDefaultSubobject<UTC_FSMComponent>(TEXT("FSM COMPONET"));
}

AActor* ATC_MinionController::GetTarget() const
{
	return CurrentTarget.IsValid() ? CurrentTarget.Get() : nullptr;
}

void ATC_MinionController::SetTarget(AActor* NewActor)
{
	if(CurrentTarget.Get() == NewActor)
		return;
	CurrentTarget = NewActor;
	TargetChanged.ExecuteIfBound(NewActor);
}

void ATC_MinionController::InitFSM()
{
	ChangeFSMState(Estate::GoToTarget);
}

void ATC_MinionController::ChangeFSMState(Estate State)
{
	if (FSMComponent) {
		FSMComponent->ChangeState(State);
	}
}
