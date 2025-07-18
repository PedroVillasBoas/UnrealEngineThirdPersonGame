// Pedro Vilas Bôas All Rights Reserved

#pragma once

#include "NativeGameplayTags.h" // We need to include this file to the *.Build.cs file of the project since this is a module that need to be build

namespace WarriorGameplayTags
{
	/** Input Tags **/
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move) // Movement
	WARRIOR_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look) // Rotation
}