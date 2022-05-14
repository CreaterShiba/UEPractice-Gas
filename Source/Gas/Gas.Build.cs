// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Gas : ModuleRules
{
	public Gas(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayAbilities", "GameplayTasks", "GameplayTags" });
        PrivateDependencyModuleNames.AddRange(new string[] {});
    }
}
