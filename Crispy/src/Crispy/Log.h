#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Crispy {
	class CRISPY_API Log {
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
// Core log
#define CY_CORE_ERROR_(...) ::Crispy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CY_CORE_WARN_(...) ::Crispy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CY_CORE_INFO_(...) ::Crispy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CY_CORE_TRACE_(...) ::Crispy::Log::GetCoreLogger()->trace(__VA_ARGS__)
// Client log
#define CY_CLIENT_ERROR_(...) ::Crispy::Log::GetClientLogger()->error(__VA_ARGS__)
#define CY_CLIENT_WARN_(...) ::Crispy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CY_CLIENT_INFO_(...) ::Crispy::Log::GetClientLogger()->info(__VA_ARGS__)
#define CY_CLIENT_TRACE_(...) ::Crispy::Log::GetClientLogger()->trace(__VA_ARGS__)