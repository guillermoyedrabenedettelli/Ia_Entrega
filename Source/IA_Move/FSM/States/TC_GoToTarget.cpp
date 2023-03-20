#include "TC_GoToTarget.h"
#include "IA_Move/Controllers/TC_MinionController.h"

void UTC_GoToTarget::OnEnterState()
{
	Super::OnEnterState();

	ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController());
	if(!MinionController)
		return;
	CurrentTarget = MinionController->GetTarget();
	AActor* Target = CurrentTarget.Get();
	OnTargetChange(Target);
	MinionController->TargetChanged.BindUObject(this,&UTC_GoToTarget::OnTargetChange);
}

void UTC_GoToTarget::OnExitState()
{
	Super::OnExitState();
	OnTargetChange(nullptr);
	if (ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController()))
	{
		MinionController->StopMovement();
	}
}

void UTC_GoToTarget::OnTargetChange(AActor* NewTarget)
{
CurrentTarget = NewTarget;
	ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController());
	if (!MinionController || !NewTarget)
		return;
	MinionController->MoveTo(NewTarget);
}
