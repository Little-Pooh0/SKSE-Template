#include "Manager.h"

namespace Manager {
	/**
	* @brief The main initialization function for the mod logic.
	* Called from the SKSE plugin entry point after game data is loaded.
	*/
	void Initialize() {
		logger::info("Manager: {} Initializing, Entering and Allocating trampoline.", Plugin::pluginName.c_str());

		// Allocate trampoline space early. Commonlib handles getting the SKSE trampoline.
		SKSE::AllocTrampoline(14);  // Only 14 bytes are necessary. SKSE and Commonlib will automatically allocate the correct amount.
		logger::info("Manager: Trampoline allocated, now Calling ResolveAddresses");

		// Resolve necessary game addresses using Address Library.
		Serialization::ResolveAddresses();

		// Install memory hooks and patches.
		Hooks::InstallHooks();
		
		logger::info("Manager: Exiting, InstallHooks finished and {} Initialization finished.", Plugin::pluginName.c_str());
		return;
	}

}
