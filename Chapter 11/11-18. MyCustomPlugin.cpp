#include "MyCustomPlugin.h"
#include "Modules/ModuleManager.h"
#include "Engine/Engine.h"

IMPLEMENT_MODULE(FMyCustomPluginModule, MyCustomPlugin)

void FMyCustomPluginModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("My Custom Plugin Loaded!"));
}

void FMyCustomPluginModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("My Custom Plugin Unloaded!"));
}
