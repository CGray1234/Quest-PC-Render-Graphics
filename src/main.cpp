
#include "Includes.hpp"

DEFINE_CONFIG(ModConfig);

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

    getModConfig().Init(modInfo);
    QuestUI::Init();
    QuestUI::Register::RegisterMainMenuModSettingsViewController<PCGraphics::pcgViewController*>(modInfo, "PC-Graphics");
    QuestUI::Register::RegisterModSettingsViewController<PCGraphics::pcgViewController*>(modInfo, "PC-Graphics");

    getLogger().info("Installing hooks...");
    
    auto& logger = getLogger();
    Hooks::InstallHooks(logger);
    
    getLogger().info("Installed all hooks!");
}
