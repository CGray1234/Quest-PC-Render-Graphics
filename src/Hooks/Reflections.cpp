#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/IntSO.hpp"

#include "UnityEngine/Application.hpp"

#include "Includes.hpp"

#include "ModConfig.hpp"

MAKE_AUTO_HOOK_MATCH(Reflections, &GlobalNamespace::MainSettingsModelSO::Load, void, GlobalNamespace::MainSettingsModelSO* self, bool forced) {
        
        if (getModConfig().Reflections.GetValue() ==  true) {
                self->mirrorGraphicsSettings->set_value(3);

                Reflections(self, forced);
        }
        else {
                self->mirrorGraphicsSettings->set_value(0);

                Reflections(self, forced);
        }
        
}
