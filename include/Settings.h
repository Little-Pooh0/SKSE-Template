#pragma once

#include "PCH.h"

namespace Settings {
	inline const char* settingPath = ("Data/SKSE/Plugins/" + PCH::pluginName + ".ini").c_str();
	void LoadSettings();
	void ResetSettings();

	namespace General {
		inline bool ModToggle = true;
	}
}