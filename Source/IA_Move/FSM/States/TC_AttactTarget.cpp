// Fill out your copyright notice in the Description page of Project Settings.


#include "Ia_Move/FSM/States/TC_AttactTarget.h"
#include "Ia_Move/Controllers/TC_MinionController.h"
#include "Ia_Move/Characters/TC_MinionCharacter.h"

void UTC_AttactTarget::OnEnterState()
{
	Super::OnEnterState();
	OnAttackTimer();
}

void UTC_AttactTarget::OnExitState()
{
	Super::OnExitState();
	if (AttackTimer.IsValid()) {
		ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
		ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
		if (!MyMinion)
			return;
		MyMinion->GetWorldTimerManager().ClearTimer(AttackTimer);
	}
}

void UTC_AttactTarget::OnAttackTimer()
{
	ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
	ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyMinion)
		return;
	const float PunchDuration = MyMinion->PlayPunchAnimation();
	if (PunchDuration > 0.f) {
		MyMinion->GetWorldTimerManager().SetTimer(AttackTimer, this, &UTC_AttactTarget::OnAttackTimer, PunchDuration);
	}
}
