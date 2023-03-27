
#include "../Actors/TC_Torret.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ATC_Torret::ATC_Torret() {
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	RootComponent = StaticMeshComponent;
}
