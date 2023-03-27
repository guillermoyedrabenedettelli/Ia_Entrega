// Fill out your copyright notice in the Description page of Project Settings.


#include "Ia_Move/FSM/States/TC_Pray.h"
#include "Ia_Move/Controllers/TC_MinionController.h"
#include "Ia_Move/Characters/TC_MinionCharacter.h"

void UTC_Pray::OnEnterState()
{
	Super::OnEnterState();
	OnPrayTimer();
}

void UTC_Pray::OnExitState()
{
	Super::OnExitState();
	if (TimerAnim.IsValid()) {
		ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
		ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
		if (!MyMinion)
			return;
		MyMinion->GetWorldTimerManager().ClearTimer(TimerAnim);
	}
}

void UTC_Pray::OnPrayTimer()
{
	ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
	ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyMinion)
		return;
	const float PunchDuration = MyMinion->PlayPrayAnimation();
	if (PunchDuration > 0.f) {
		MyMinion->GetWorldTimerManager().SetTimer(TimerAnim, this, &UTC_Pray::OnNextTarget, PunchDuration, false);
	}

}

void UTC_Pray::OnNextTarget()
{
	ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
	ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyMinion)
		return;

	MyController->ChangePatrols();
	MyController->ChangeFSMState(Estate::GoToTarget);


}
