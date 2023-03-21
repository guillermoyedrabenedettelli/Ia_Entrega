#include "TC_GoToTarget.h"
#include "IA_Move/Controllers/TC_MinionController.h"
#include "Logging/LogMacros.h"
#include "Math/Vector.h"

void UTC_GoToTarget::OnEnterState()
{
	Super::OnEnterState();

	ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController());
	if (!MinionController)
		return;
	CurrentTarget = MinionController->GetTarget();
	AActor* Target = CurrentTarget.Get();
	ObjectTarget = Target;
	OnTargetChange(Target);
	MinionController->TargetChanged.BindUObject(this, &UTC_GoToTarget::OnTargetChange);
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

void UTC_GoToTarget::OnUpdateState(float DeltaTime)
{
	
	if (ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController()))
	{
		
		Distance_ = ObjectTarget->GetActorLocation() - MinionController->GetPawn()->GetActorLocation();
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle working %f"), Distance_.Size());
		if (Distance_.Size() > 150)
		{
			MinionController->MoveTo(ObjectTarget);
		}
		
	}

}
	
	


void UTC_GoToTarget::OnTargetChange(AActor* NewTarget)
{
	CurrentTarget = NewTarget;
	ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController());
	if (!MinionController || !NewTarget)
		return;
	MinionController->MoveTo(NewTarget);
	UE_LOG(LogTemp, Error, TEXT("NewTarget"));
}
