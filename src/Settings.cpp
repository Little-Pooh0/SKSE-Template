#include "Settings.h"

namespace Settings {
    void LoadSettings() {
        CSimpleIniW ini;
        ini.SetUnicode();

        if (!std::filesystem::exists(settingPath)) {
            logger::info("No {} file found, creating new with default values", settingPath);
            ResetSettings();
        } else {
            ini.LoadFile(settingPath);

            General::ModToggle = ini.GetBoolValue(L"General", L"ModToggle", General::ModToggle);
            ini.SetBoolValue(L"General", L"ModToggle", General::ModToggle, L"; Main Mod Toggle");


            ini.SaveFile(settingPath);
            logger::info("Settings Loaded");
        }
    }

    void ResetSettings() {
		CSimpleIniW ini;
		ini.SetUnicode();
		ini.Reset();

        General::ModToggle = true;
        logger::info("Settings Reset");
    }
}