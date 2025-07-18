// Pedro Vilas Bôas All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

// Struct to Map an Input Tag to an Input Action
USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY() // This has to be here, else we won't be able to compile the code

public:
	// With this meta identifier we're only allowed to select a tag that starts with this Input Tag for this variable
	// We did this because it'll help us select the input tag in the editor since we'll have a lot of tags
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

};
/**
 * 
 */
UCLASS()
class WARRIOR_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingcontext;

	// For an Array of Structs there's another method specifier that can be used to improve its readability
	// That's the TitleProperty | The value set here can be a variable inside the Struct
	// doing this will use this input action's name as the name for the rows inside of this array (more inside the Editor)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
