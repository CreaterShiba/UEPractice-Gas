// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "MyAbilitySystemGlobals.h"
#include "GasAbilityTypes.h"

void UMyBlueprintFunctionLibrary::AddAbilityToComponent(AActor* Target, UAbilitySystemComponent* AbilitySystem, TSubclassOf<class UGameplayAbility> Ability)
{
	if (Target && AbilitySystem && Ability)
	{
		AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, 1));
	}
}

void UMyBlueprintFunctionLibrary::GiveAbilityToComponent(AActor* Target, UAbilitySystemComponent* AbilitySystem, TArray<TSubclassOf<class UGameplayAbility>> AbilityList)
{
	if (AbilitySystem && Target)
	{
		if (AbilityList.Num() > 0)
		{
			int32 inputID(0);
			for (auto Ability : AbilityList)
			{
				if (Ability)
				{
					AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, inputID++));
				}
			}
			AbilitySystem->InitAbilityActorInfo(Target, Target);
		}
	}
}

void UMyBlueprintFunctionLibrary::SendGamePlayEventToActorForUMG(AActor* Actor, FGameplayTag EventTag, FGameplayAttribute GamePlayAttribute, FGameplayEventData Payload, FReceiveChangeAttributeDelegate OnChangeEvent)
{
	if (::IsValid(Actor))
	{
		UAbilitySystemComponent* AbilitySystemComponent = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
		if (AbilitySystemComponent != nullptr && IsValidChecked(AbilitySystemComponent))
		{
			FGasGameplayEffectContext* GasEffectContext = static_cast<FGasGameplayEffectContext*>(Payload.ContextHandle.Get());
			if (GasEffectContext != nullptr)
			{
				GasEffectContext->umgReceiveAttribute = GamePlayAttribute;
				GasEffectContext->OnChangeAttribute = OnChangeEvent;
				FScopedPredictionWindow NewScopedWindow(AbilitySystemComponent, true);
				AbilitySystemComponent->HandleGameplayEvent(EventTag, &Payload);
				return;
			}

		}
		ABILITY_LOG(Error, TEXT("UAbilitySystemBlueprintLibrary::SendGameplayEventToActor: Invalid ability system component retrieved from Actor %s. EventTag was %s"), *Actor->GetName(), *EventTag.ToString());
	}
}

FGameplayAttribute UMyBlueprintFunctionLibrary::GetGamePlayAttribute(const FGameplayEffectContextHandle& EffectContext)
{
	const FGasGameplayEffectContext* GasEffectContext = static_cast<const FGasGameplayEffectContext*>(EffectContext.Get());
	if (GasEffectContext)
	{
		return GasEffectContext->umgReceiveAttribute;
	}
	return GasEffectContext->defaultAttribute;

	//static FGameplayAttribute tempData = FGameplayAttribute();
	//return tempData;
}

FReceiveChangeAttributeDelegate UMyBlueprintFunctionLibrary::GetReceiveChangeDelegate(const FGameplayEffectContextHandle& EffectContext)
{
	const FGasGameplayEffectContext* GasEffectContext = static_cast<const FGasGameplayEffectContext*>(EffectContext.Get());

	return GasEffectContext->OnChangeAttribute;
}