#include "Includes.hpp"

using namespace PCGraphics;

DEFINE_TYPE(PCGraphics, pcgViewController);

void pcgViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {

    if (firstActivation) {
        UnityEngine::GameObject *container = QuestUI::BeatSaberUI::CreateScrollView(get_rectTransform());

        AddConfigValueToggle(container->get_transform(), getModConfig().DistortionWalls)->get_gameObject();
        AddConfigValueToggle(container->get_transform(), getModConfig().Shockwaves)->get_gameObject();
        AddConfigValueToggle(container->get_transform(), getModConfig().Reflections)->get_gameObject();
    }
}

void pcgViewController::DidDeactivate(bool removedFromHierarchy, bool screenSystemDisabling) {

    JNIUtils::RestartApp();
}
