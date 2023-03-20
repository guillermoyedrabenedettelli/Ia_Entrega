// Fill out your copyright notice in the Description page of Project Settings.


#include "TC_MinionCharacter.h"
#include "Components/SphereComponent.h"
#include "IA_Move/IA_MoveCharacter.h"
#include "IA_Move/Controllers/TC_MinionController.h"

// Sets default values
ATC_MinionCharacter::ATC_MinionCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	sphereComponent->SetupAttachment(RootComponent);
	sphereComponent->SetSphereRadius(200.f);

}

// Called when the game starts or when spawned
void ATC_MinionCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (sphereComponent)
	{
		sphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ATC_MinionCharacter::OnSphereOverLap);
	}
}

void ATC_MinionCharacter::OnSphereOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AIA_MoveCharacter>())
	{
		if (ATC_MinionController* MyController = Cast<ATC_MinionController>(GetController()))
		{
		MyController->ChangeFSMState(Estate::AttackTarget);
		}
	}
}


