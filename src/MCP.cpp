#include "MCP.h"

namespace MCP {
	void Register() {
		logger::info("Registering MCP functionality");
		if (!SKSEMenuFramework::IsInstalled()) {
			return;
			logger::error("SKSEMenuFramework is not installed. MCP functionality cannot be registered.");
		}
		SKSEMenuFramework::SetSection("{}", SKSE::PluginDeclaration::GetSingleton()->GetName());
		SKSEMenuFramework::AddSectionItem("General Settings", General::Render);
	}

	void __stdcall General::Render() {
	}
}
