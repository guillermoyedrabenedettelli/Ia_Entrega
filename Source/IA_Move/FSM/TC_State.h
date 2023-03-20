// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TC_State.generated.h"

class AController;

UCLASS()
class IA_MOVE_API UTC_State : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void OnEnterState(){};
	virtual void OnUpdateState(float DeltaTime){};
	virtual void OnExitState(){};

	virtual void InitState(AController* NewOwnerController);

protected:
	AController* GetOwnerController() const;

	TWeakObjectPtr<AController> OwnerController =nullptr;
};
