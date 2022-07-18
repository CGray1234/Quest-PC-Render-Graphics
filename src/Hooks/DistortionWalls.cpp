#include "main.hpp"

#include "hooks.hpp"

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

#include "Config.hpp"

using namespace GlobalNamespace;

MAKE_AUTO_HOOK_MATCH(DistortionWalls, &GlobalNamespace::ConditionalMaterialSwitcher::Awake, void, GlobalNamespace::ConditionalMaterialSwitcher* instance)
{
        BoolSO* use_grappass = (BoolSO*)UnityEngine::ScriptableObject::CreateInstance(csTypeOf(BoolSO*));
        use_grappass->value = getGraphicsConfig().enablePCWalls.GetValue();
        instance->value = use_grappass;

        DistortionWalls(instance);
}

MAKE_AUTO_HOOK_MATCH(Activation_Awake, &GlobalNamespace::ConditionalActivation::Awake, void, GlobalNamespace::ConditionalActivation* instance)
{
    Activation_Awake(instance);

    instance->get_gameObject()->SetActive(getGraphicsConfig().enablePCWalls.GetValue());
    UnityEngine::QualitySettings::set_antiAliasing(1);
}
