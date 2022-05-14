// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystemComponent.h"
#include "ReceiveChangeAttributeGA.h"
#include "MyBlueprintFunctionLibrary.generated.h"
/**
 * 
 */
UCLASS()
class GAS_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Target"))
	static void AddAbilityToComponent(AActor* Target, UAbilitySystemComponent* AbilitySystem, TSubclassOf<class UGameplayAbility> Ability);

	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Target"))
	static void GiveAbilityToComponent(AActor* Target, UAbilitySystemComponent* AbilitySystem, TArray<TSubclassOf<class UGameplayAbility>> AbilityList);

	UFUNCTION(BlueprintCallable, meta = (DefaultToSelf = "Actor"))
	static void SendGamePlayEventToActorForUMG(AActor* Actor, FGameplayTag EventTag, FGameplayAttribute GamePlayAttribute, FGameplayEventData Payload, FReceiveChangeAttributeDelegate OnChangeEvent);
	
	UFUNCTION(BlueprintPure)
	static FGameplayAttribute GetGamePlayAttribute(const FGameplayEffectContextHandle& EffectContext);

	UFUNCTION(BlueprintPure)
	static FReceiveChangeAttributeDelegate GetReceiveChangeDelegate(const FGameplayEffectContextHandle& EffectContext);
};
