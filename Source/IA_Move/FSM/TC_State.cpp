// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_State.h"
#include "GameFramework/Controller.h"

void UTC_State::InitState(AController* NewOwnerController)
{
	OwnerController = NewOwnerController;
}

AController* UTC_State::GetOwnerController() const
{
	return OwnerController.IsValid() ? OwnerController.Get() : nullptr;
}
