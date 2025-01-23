#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_SetupDataBase.generated.h"

class UHamsterGameplayAbility;
class UHamsterAbilitySystemComponent;

UCLASS()
class HAMSTER_API UDataAsset_SetupDataBase : public UDataAsset
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UHamsterGameplayAbility>> ActivateOnGinvenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UHamsterGameplayAbility>> ReactiveAbilities;

public:
	virtual void GiveToAbilitySystemComponent(UHamsterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	void GrantAbilities(const TArray<TSubclassOf<UHamsterGameplayAbility>>& InAbilitiesToGive, UHamsterAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
