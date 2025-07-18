// Pedro Vilas Bôas All Rights Reserved


#include "Characters/WarriorBaseCharacter.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/WarriorAttributeSet.h"


// Sets default values
AWarriorBaseCharacter::AWarriorBaseCharacter()
{
	// We changed to false because not all Character Classes in the project will need Ticking
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// We set this to false because some of the VFX will project Decals on the ground
	// And we want that to just affect the ground, and not the Character Mesh
	GetMesh()->bReceivesDecals = false;
	
	// Component for Unreal's Ability System
	WarriorAbilitySystemComponent = CreateDefaultSubobject<UWarriorAbilitySystemComponent>(TEXT("WarriorAbilitySystemComponent"));
	// Component for the Attributes Component from the Ability System
	WarriorAttributeSet = CreateDefaultSubobject<UWarriorAttributeSet>(TEXT("WarriorAttributeSet"));

}

UAbilitySystemComponent* AWarriorBaseCharacter::GetAbilitySystemComponent() const
{
	return GetWarriorAbilitySystemComponent();
}

void AWarriorBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (WarriorAbilitySystemComponent)
	{
		// For this Ability System Component the 'Owner Actor' is the same as the 'Avatar Actor'
		// But that's not always the case. Depending on what kind of game we are making, 
		// Sometimes the player state can be the 'Owner Actor' for an Ability System Component
		WarriorAbilitySystemComponent->InitAbilityActorInfo(this, this); // Sets the Actor Info
	}
}
