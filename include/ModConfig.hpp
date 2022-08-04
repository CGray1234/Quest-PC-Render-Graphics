#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,

    CONFIG_VALUE(DistortionWalls, bool, "Enable PC Walls", true);
    CONFIG_VALUE(Shockwaves, bool, "Enable Shockwaves", true);
    CONFIG_VALUE(Reflections, bool, "Enable Reflections", true);

    CONFIG_INIT_FUNCTION(

        CONFIG_INIT_VALUE(DistortionWalls);
        CONFIG_INIT_VALUE(Shockwaves);
        CONFIG_INIT_VALUE(Reflections);
    )
)
