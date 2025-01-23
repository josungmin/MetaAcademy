#pragma once
#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "HamsterInputComponent.generated.h"


UCLASS()
class HAMSTER_API UHamsterInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunc>
	void BindInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
};


template<class UserObject, typename CallbackFunc>
inline void UHamsterInputComponent::BindInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data is null"));

	UInputAction* FoundAction = InInputConfig->FindInputActionByTag(InInputTag);
	if (!FoundAction)
	{
		checkf(InInputConfig, TEXT("InInputTag is not found"));
		return;
	}

	BindAction(FoundAction, TriggerEvent, ContextObject, Func);
}
