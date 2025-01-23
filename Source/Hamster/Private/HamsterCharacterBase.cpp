#include "HamsterCharacterBase.h"
#include "Abilities/HamsterAbilitySystemComponent.h"
#include "Abilities/HamsterAttributeSet.h"

AHamsterCharacterBase::AHamsterCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	HamsterAbilitySystemComponent = CreateDefaultSubobject<UHamsterAbilitySystemComponent>(TEXT("HamsterAbilitySystemComponent"));
	HamsterAtributeSet = CreateDefaultSubobject<UHamsterAttributeSet>(TEXT("HamsterAtributeSet"));
}

void AHamsterCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHamsterCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (HamsterAbilitySystemComponent)
	{
		HamsterAbilitySystemComponent->InitAbilityActorInfo(this,this);

		ensureMsgf(!CharacterSetupData.IsNull(), TEXT("Forgot to assign start up data to %s"), *GetName());
	}
}

UAbilitySystemComponent* AHamsterCharacterBase::GetAbilitySystemComponent() const
{
	return GetHamsterAbilitySystemComponent();
}


