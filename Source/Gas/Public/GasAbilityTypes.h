// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "ReceiveChangeAttributeGA.h"

#include "GasAbilityTypes.generated.h"

USTRUCT(BlueprintType)
struct FGasGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:

	FGameplayAttribute umgReceiveAttribute;
	FGameplayAttribute defaultAttribute;

	FReceiveChangeAttributeDelegate OnChangeAttribute;

protected:

public:
	/** Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const override
	{
		return StaticStruct();
	}

	/** Creates a copy of this context, used to duplicate for later modifications */
	virtual FGasGameplayEffectContext* Duplicate() const override
	{
		FGasGameplayEffectContext* NewContext = new FGasGameplayEffectContext();
		*NewContext = *this;
		NewContext->AddActors(Actors);
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}
};

template <>
struct TStructOpsTypeTraits<FGasGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FGasGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true // Necessary so that TSharedPtr<FHitResult> Data is copied around
	};
};