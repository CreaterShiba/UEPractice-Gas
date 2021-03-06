// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGasCharacter.h"

AMyGasCharacter::AMyGasCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// AbilitySystemコンポーネントを作成する
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	PlayerAttributeSet = CreateDefaultSubobject<UPlayerAttributeSet>(TEXT("AttributeSet"));
}

// Abilityの登録
void AMyGasCharacter::AddAbility(TSubclassOf<class UGameplayAbility> Ability, int32 AbilityLevel) 
{
	if (AbilitySystemComponent && Ability) 
	{
		AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), AbilityLevel, -1));
	}
}

// Abilityの発動
bool AMyGasCharacter::ActivateAbilitiesWithTags(FGameplayTagContainer AbilityTags, bool bAllowRemoteActivation)
{
	if (AbilitySystemComponent) 
	{
		return AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags, bAllowRemoteActivation);
	}
	return false;
}

// Effectの登録
void AMyGasCharacter::AddEffect(TSubclassOf<class UGameplayEffect> Effect, int32 EffectLevel)
{
	if (AbilitySystemComponent && Effect) 
	{
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(Effect, EffectLevel, EffectContext);
		if (NewHandle.IsValid()) 
		{
			AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent);
		}
	}
}