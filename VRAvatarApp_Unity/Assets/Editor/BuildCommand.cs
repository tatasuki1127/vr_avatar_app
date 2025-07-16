using System.Collections.Generic;
using UnityEditor;
using UnityEngine;

public class BuildCommand
{
    public static void PerformBuild()
    {
        Debug.Log("🚀 Starting Unity iOS Build for VR Avatar App");
        
        // Build settings
        BuildPlayerOptions buildPlayerOptions = new BuildPlayerOptions();
        buildPlayerOptions.scenes = GetScenes();
        buildPlayerOptions.locationPathName = "unity_build";
        buildPlayerOptions.target = BuildTarget.iOS;
        buildPlayerOptions.options = BuildOptions.None;
        
        // Player settings for iOS
        PlayerSettings.iOS.applicationDisplayName = "VR Avatar App";
        PlayerSettings.SetApplicationIdentifier(BuildTargetGroup.iOS, "com.vr.avatar1");
        PlayerSettings.iOS.buildNumber = "1";
        PlayerSettings.bundleVersion = "1.0";
        PlayerSettings.iOS.targetOSVersionString = "15.0";
        
        // IL2CPP settings
        PlayerSettings.SetScriptingBackend(BuildTargetGroup.iOS, ScriptingImplementation.IL2CPP);
        PlayerSettings.SetArchitecture(BuildTargetGroup.iOS, 1); // ARM64
        
        // Build
        var report = BuildPipeline.BuildPlayer(buildPlayerOptions);
        
        if (report.summary.result == UnityEditor.Build.Reporting.BuildResult.Succeeded)
        {
            Debug.Log("✅ Unity iOS Build Succeeded");
            Debug.Log($"📦 Build size: {report.summary.totalSize} bytes");
            Debug.Log($"⏱️ Build time: {report.summary.totalTime}");
        }
        else
        {
            Debug.LogError("❌ Unity iOS Build Failed");
            Debug.LogError($"Error: {report.summary.result}");
            EditorApplication.Exit(1);
        }
    }
    
    private static string[] GetScenes()
    {
        List<string> scenes = new List<string>();
        for (int i = 0; i < EditorBuildSettings.scenes.Length; i++)
        {
            if (EditorBuildSettings.scenes[i].enabled)
            {
                scenes.Add(EditorBuildSettings.scenes[i].path);
            }
        }
        return scenes.ToArray();
    }
}