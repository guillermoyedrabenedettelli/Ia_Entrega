#pragma once

#include "CoreMinimal.h"
#include "Ia_Move/FSM/TC_State.h"
#include "TC_GoToTarget.generated.h"


UCLASS()
class IA_MOVE_API UTC_GoToTarget : public UTC_State
{
	GENERATED_BODY()

public:
	void OnEnterState() override;
	void OnExitState() override;
	void OnUpdateState(float DeltaTime) override;
	int range = 180; //50
	bool objetivo_cerca = false;
private:
	TWeakObjectPtr<AActor> CurrentTarget = nullptr;
	void OnTargetChange(AActor* NewTarget);
	UPROPERTY()
		AActor* ObjectTarget = nullptr;
	FVector Distance_;
};
