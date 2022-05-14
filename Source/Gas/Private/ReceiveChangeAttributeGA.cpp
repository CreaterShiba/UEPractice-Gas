// Fill out your copyright notice in the Description page of Project Settings.


#include "ReceiveChangeAttributeGA.h"

void UReceiveChangeAttributeGA::CallOnReceiveChangeAttribute(float value)
{
	OnReceiveChangeAttribute.ExecuteIfBound(value);
}