////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;

public class InventoryModule : ModuleRules
{
    public InventoryModule(ReadOnlyTargetRules Target) : base(Target)
    {
        // PrivatePCHHeaderFile = "InventoryGame.h";

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Noesis", "NoesisRuntime" });
    }
}
