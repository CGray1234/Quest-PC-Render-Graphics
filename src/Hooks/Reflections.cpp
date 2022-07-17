#include "main.hpp"

#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/IntSO.hpp"

#include "hooks.hpp"

MAKE_AUTO_HOOK_MATCH(Reflections, &GlobalNamespace::MainSettingsModelSO::Load, void, GlobalNamespace::MainSettingsModelSO* self, bool forced) {
        self->mirrorGraphicsSettings->set_value(3);

        Reflections(self, forced);
}
