// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Dank_Soles : ModuleRules
{
	public Dank_Soles(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
