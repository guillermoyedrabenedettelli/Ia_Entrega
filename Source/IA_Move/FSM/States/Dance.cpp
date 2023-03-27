// Fill out your copyright notice in the Description page of Project Settings.


#include "Dance.h"
#include "Ia_Move/Controllers/TC_MinionController.h"
#include "Ia_Move/Characters/TC_MinionCharacter.h"


void UDance::OnEnterState()
{
	Super::OnEnterState();
	DanceTimer();
}

void UDance::OnExitState()
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

void UDance::DanceTimer()
{
	ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
	ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyMinion)
		return;
	const float PunchDuration = MyMinion->PlayDanceAnimation();
	if (PunchDuration > 0.f) {
		MyMinion->GetWorldTimerManager().SetTimer(TimerAnim, this, &UDance::OnNextTarget, PunchDuration, false);
	}

}

void UDance::OnNextTarget()
{
	ATC_MinionController* MyController = Cast<ATC_MinionController>(GetOwnerController());
	ATC_MinionCharacter* MyMinion = MyController ? Cast<ATC_MinionCharacter>(MyController->GetPawn()) : nullptr;
	if (!MyMinion)
		return;

	MyController->ChangePatrols();
	MyController->ChangeFSMState(Estate::GoToTarget);


}
