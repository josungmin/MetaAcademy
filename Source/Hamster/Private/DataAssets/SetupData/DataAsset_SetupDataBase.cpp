#include "DataAssets/SetupData/DataAsset_SetupDataBase.h"
#include "Abilities/HamsterGameplayAbility.h"
#include "Abilities/HamsterAbilitySystemComponent.h"


void UDataAsset_SetupDataBase::GiveToAbilitySystemComponent(UHamsterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGinvenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);
}


void UDataAsset_SetupDataBase::GrantAbilities(const TArray<TSubclassOf<UHamsterGameplayAbility>>& InAbilitiesToGive, UHamsterAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UHamsterGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec Spec(Ability);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		Spec.Level = ApplyLevel;

		InASCToGive->GiveAbility(Spec);
	}
}
