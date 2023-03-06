#pragma once

#include <memory>

#include "Core.h";
#include "spdlog/spdlog.h"

namespace Robles {

	class ROBLES_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger>  s_CoreLogger;
		static std::shared_ptr<spdlog::logger>  s_ClientLogger;
	};

}


//Core log macros
#define RS_CORE_TRACE(...)    ::Robles::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RS_CORE_INFO(...)     ::Robles::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RS_CORE_WARN(...)     ::Robles::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RS_CORE_ERROR(...)    ::Robles::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RS_CORE_CRITICAL(...) ::Robles::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros
#define RS_TRACE(...)         ::Robles::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RS_INFO(...)          ::Robles::Log::GetClientLogger()->info(__VA_ARGS__)
#define RS_WARN(...)          ::Robles::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RS_ERROR(...)         ::Robles::Log::GetClientLogger()->error(__VA_ARGS__)
#define RS_CRITICAL(...)      ::Robles::Log::GetClientLogger()->critical(__VA_ARGS__)
