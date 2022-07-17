#include "main.hpp"

#include "GlobalNamespace/MainSettingsModelSO.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/IntSO.hpp"

#include "hooks.hpp"

MAKE_AUTO_HOOK_MATCH(PC_Graphics, &GlobalNamespace::MainSettingsModelSO::Load, void, GlobalNamespace::MainSettingsModelSO* self, bool forced) {
    
    self->screenDisplacementEffectsEnabled->set_value(true);
    self->maxShockwaveParticles->set_value(2);
    self->mirrorGraphicsSettings->set_value(3);

    PC_Graphics(self, forced);
}

#include "GlobalNamespace/ConditionalMaterialSwitcher.hpp"
#include "GlobalNamespace/ConditionalActivation.hpp"
#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/BloomPrePass.hpp"

#include "UnityEngine/ScriptableObject.hpp"
#include "UnityEngine/Renderer.hpp"
#include "UnityEngine/Transform.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/QualitySettings.hpp"
#include "UnityEngine/ScriptableObject.hpp"
#include "UnityEngine/Vector3.hpp"
#include "UnityEngine/Material.hpp"
#include "UnityEngine/MeshRenderer.hpp"
#include "UnityEngine/PrimitiveType.hpp"

using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(DistortionWalls, &GlobalNamespace::ConditionalMaterialSwitcher::Awake, void, GlobalNamespace::ConditionalMaterialSwitcher* instance)
{
    BoolSO* use_grappass = (BoolSO*)UnityEngine::ScriptableObject::CreateInstance(csTypeOf(BoolSO*));
    use_grappass->value = true;
    instance->value = use_grappass;

    DistortionWalls(instance);
}