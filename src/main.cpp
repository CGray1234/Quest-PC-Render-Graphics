#include "main.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "hooks.hpp"
#include "modloader/shared/modloader.hpp"
#include "questui/shared/QuestUI.hpp"
#include "questui/shared/BeatSaberUI.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"

#include "Config.hpp"

using namespace GlobalNamespace;
using namespace UnityEngine;
using namespace QuestUI::BeatSaberUI;

DEFINE_CONFIG(GraphicsConfig);

void DidActivate(HMUI::ViewController *self, bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling) {

    if(firstActivation) {

        UnityEngine::GameObject *container = QuestUI::BeatSaberUI::CreateScrollableSettingsContainer(self->get_transform());
        UnityEngine::GameObject *anotherContainer = QuestUI::BeatSaberUI::CreateScrollView(self->get_transform());

        AddConfigValueToggle(anotherContainer->get_transform(), getGraphicsConfig().enablePCWalls)->get_gameObject();
        AddConfigValueToggle(anotherContainer->get_transform(), getGraphicsConfig().enableShockwaves)->get_gameObject();
        AddConfigValueIncrementFloat(anotherContainer->get_transform(), getGraphicsConfig().enableMirror, 0, 1, 0, 3);

        Transform* parent = anotherContainer->get_transform();
        auto layout = QuestUI::BeatSaberUI::CreateHorizontalLayoutGroup(parent);  layout->GetComponent<UnityEngine::UI::LayoutElement*>()->set_preferredWidth(60.0f); 
        layout->set_childControlWidth(true); 
        auto layoutParent = layout->get_transform();
    }
}

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load(); // Load the config file
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    QuestUI::Init();

    // REGISTERS MOD IN BOTH MOD MENUS
    QuestUI::Register::RegisterMainMenuModSettingsViewController(modInfo, DidActivate);
    QuestUI::Register::RegisterModSettingsViewController(modInfo, DidActivate);

    getGraphicsConfig().Init(modInfo);

    getLogger().info("Installing hooks...");
    
    auto& logger = getLogger();
    Hooks::InstallHooks(logger);

    getLogger().info("Installed all hooks!");
}
