#pragma once

#include "PCH.h"
#include "Plugin.h"

namespace Settings {
	inline const char* settingPath = ("Data/SKSE/Plugins/" + Plugin::pluginName + ".ini").c_str();
	void LoadSettings();
	void ResetSettings();

	namespace General {
		inline bool ModToggle = true;
	}
}