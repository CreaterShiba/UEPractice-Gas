// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilitySystemGlobals.h"
#include "GasAbilityTypes.h"

FGameplayEffectContext* UMyAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FGasGameplayEffectContext();
}
