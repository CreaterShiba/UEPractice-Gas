// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilityTask_WAC.h"

#include "AbilitySystemComponent.h"

#include "GameplayEffectExtension.h"
#include "AbilitySystemGlobals.h"

UAbilityTask_WaitAttributeChange* UMyAbilityTask_WAC::MyWaitForAttributeChange(UGameplayAbility* OwningAbility, FGameplayAttribute InAttribute, FGameplayTag InWithTag, FGameplayTag InWithoutTag, bool TriggerOnce, AActor* OptionalExternalOwner)
{
	return nullptr;
}

bool UMyAbilityTask_WAC::MyTwoWaitForAttributeChange(UGameplayAbility* OwningAbility, FGameplayAttribute InAttribute, FGameplayTag InWithTag, FGameplayTag InWithoutTag, bool TriggerOnce, AActor* OptionalExternalOwner)
{
	return IsValid(OwningAbility);
}
