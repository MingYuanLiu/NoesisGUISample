////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System.Collections.Generic;

public class SamplesTarget : TargetRules
{
    public SamplesTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        //bOverrideBuildEnvironment = true;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        ExtraModuleNames.Add("DataBindingModule");
        ExtraModuleNames.Add("InventoryModule");
        ExtraModuleNames.Add("LocalizeModule");
        ExtraModuleNames.Add("LoginModule");
        ExtraModuleNames.Add("UserControlModule");
        ExtraModuleNames.Add("WorldSpaceUIModule");
        ExtraModuleNames.Add("SamplesModule");
    }
}
