// Pedro Vilas Bôas All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "WarriorInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObect, CallbackFunc Func);
	
};

template<class UserObject, typename CallbackFunc>
inline void UWarriorInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObect, CallbackFunc Func)
{
	// By using check and checking this way, if this InInputConfig is null for some reason
	// It'll trigger an assertion and crash the editor intentionally. Since pointers canno't be null during execution
	// Which in turn will help us identify the bug more easily
	//check(InInputConfig);
	
	// Optionally we can use the checkf to check the input
	// This one gives more information for debugging
	checkf(InInputConfig, TEXT("Input config data asset is null, can not proceed with binding."));

	if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObect, Func);
	}
}
