#include "main.hpp"

#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/IntSO.hpp"

#include "hooks.hpp"

#include "Config.hpp"

MAKE_AUTO_HOOK_MATCH(Shockwaves, &GlobalNamespace::MainSettingsModelSO::Load, void, GlobalNamespace::MainSettingsModelSO* self, bool forced) {
        self->screenDisplacementEffectsEnabled->set_value(getGraphicsConfig().enableShockwaves.GetValue());
        self->maxShockwaveParticles->set_value(2);

        Shockwaves(self, forced);
}
