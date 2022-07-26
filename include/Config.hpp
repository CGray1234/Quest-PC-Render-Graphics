#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(GraphicsConfig,

    CONFIG_VALUE(enablePCWalls, bool, "Enable PC Walls", true);
    CONFIG_VALUE(enableShockwaves, bool, "Enable Shockwaves", true);
    CONFIG_VALUE(enableMirror, float, "Enable High-Quality Mirror Effects", 3);

    CONFIG_INIT_FUNCTION(

        CONFIG_INIT_VALUE(enablePCWalls);
        CONFIG_INIT_VALUE(enableShockwaves);
        CONFIG_INIT_VALUE(enableMirror);
    )
)
