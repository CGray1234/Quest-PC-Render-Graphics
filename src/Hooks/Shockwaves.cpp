#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/IntSO.hpp"

#include "Includes.hpp"

#include "ModConfig.hpp"

MAKE_AUTO_HOOK_MATCH(Shockwaves, &GlobalNamespace::MainSettingsModelSO::Load, void, GlobalNamespace::MainSettingsModelSO* self, bool forced) {

        if (getModConfig().Shockwaves.GetValue() == true) {
                self->screenDisplacementEffectsEnabled->set_value(true);

                Shockwaves(self, forced);
        }
        else {
                self->screenDisplacementEffectsEnabled->set_value(false);

                Shockwaves(self, forced);
        }
}
