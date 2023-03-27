// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_MinionController.h"
#include "AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "IA_Move/IA_MoveCharacter.h"
#include "AIModule/Classes/Perception/AISenseConfig_Damage.h"

ATC_MinionController::ATC_MinionController() : Super()
{
	FSMComponent = CreateDefaultSubobject<UTC_FSMComponent>(TEXT("FSM COMPONET"));
	ConfigSight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Config Sight"));
	ConfigDamage = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("Damage Config"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));

	ConfigSight->SightRadius = 300.f;
	ConfigSight->LoseSightRadius = ConfigSight->SightRadius + 20.f;
	ConfigSight->PeripheralVisionAngleDegrees = 360.f;
	ConfigSight->DetectionByAffiliation.bDetectEnemies = true;
	ConfigSight->DetectionByAffiliation.bDetectFriendlies = true;
	ConfigSight->DetectionByAffiliation.bDetectNeutrals = true;

	PerceptionComponent->ConfigureSense(*ConfigSight);
	PerceptionComponent->ConfigureSense(*ConfigDamage);
	PerceptionComponent->SetDominantSense(ConfigSight->GetSenseImplementation());

}

AActor* ATC_MinionController::GetTarget() const
{
	return CurrentTarget.IsValid() ? CurrentTarget.Get() : nullptr;
}

void ATC_MinionController::SetTarget(AActor* NewActor)
{
	if (CurrentTarget.Get() == NewActor)
		return;
	CurrentTarget = NewActor;
	TargetChanged.ExecuteIfBound(NewActor);
	ChangeFSMState(Estate::GoToTarget);
}

void ATC_MinionController::InitFSM()
{
	ChangeFSMState(Estate::GoToTarget);
	MainTarget = CurrentTarget;
}

void ATC_MinionController::ChangeFSMState(Estate State)
{
	if (FSMComponent) {
		FSMComponent->ChangeState(State);
	}
}

void ATC_MinionController::BeginPlay()
{
	Super::BeginPlay();
	PerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ATC_MinionController::OnPerceptionUpdate);

}

void ATC_MinionController::OnPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed()) {
		if (UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus) == UAISense_Sight::StaticClass() ||
			UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus) == UAISense_Damage::StaticClass())
		{
			ReactToSight(Actor);
		}
	}
	else {
		if (!LostTargetTimer.IsValid()) {
			GetWorldTimerManager().SetTimer(LostTargetTimer, this, &ATC_MinionController::OnLostTarget, 3.f);
		}
	}
}

void ATC_MinionController::ReactToSight(AActor* Target)
{
	if (Target->IsA<AIA_MoveCharacter>()) {
		if (LostTargetTimer.IsValid()) {
			GetWorldTimerManager().ClearTimer(LostTargetTimer);
		}
		SetTarget(Target);
	}
}

void ATC_MinionController::OnLostTarget()
{
	if (LostTargetTimer.IsValid()) {
		GetWorldTimerManager().ClearTimer(LostTargetTimer);
	}
	SetTarget(MainTarget.Get());
}

void ATC_MinionController::ChangePatrols()
{
	if (TargetsPath.IsEmpty())
		return;
	++patrolNumber;
	if (patrolNumber >= TargetsPath.Num())
	{
	patrolNumber=0;
	}
	SetTarget(TargetsPath[patrolNumber]);
}
