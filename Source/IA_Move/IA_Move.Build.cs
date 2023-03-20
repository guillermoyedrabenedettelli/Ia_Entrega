// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IA_Move : ModuleRules
{
	public IA_Move(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
