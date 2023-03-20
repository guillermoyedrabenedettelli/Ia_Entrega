// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_FSMComponent.h"
#include "../FSM/TC_State.h"
#include "GameFramework/Controller.h"




// Called when the game starts
void UTC_FSMComponent::BeginPlay()
{
	Super::BeginPlay();

	for (const TPair<Estate, TSoftClassPtr<UTC_State>> State : States)
	{
		UObject* StateToLoad = State.Value.ToSoftObjectPath().TryLoad();
		if (UTC_State* BaseState = Cast<UTC_State>(StateToLoad))
		{
			BaseState->InitState(Cast<AController>(GetOwner()));
		}
	}
	
}


void UTC_FSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (UTC_State* State = CurrentState.IsValid() ? CurrentState.Get() : nullptr) {
		State->OnUpdateState(DeltaTime);
	}
}

void UTC_FSMComponent::ChangeState(Estate NewState)
{
	if(!States.Contains(NewState))
		return;
	TSoftClassPtr<UTC_State> MapState = States[NewState];
	UObject* StateToLoad = MapState.ToSoftObjectPath().TryLoad();
	UTC_State* StateToChange = Cast<UTC_State>(StateToLoad);
	UTC_State* State = CurrentState.IsValid() ? CurrentState.Get() : nullptr;

	if (State) {
		State->OnExitState();
	}
	if (StateToChange) {
		CurrentState = StateToChange;
		StateToChange->OnExitState();
	}
}

