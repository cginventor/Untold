#pragma once

#include "Untold/Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Untold
{

	class UNTOLD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr <spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr < spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log macros
#define UT_CORE_TRACE(...)   ::Untold::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UT_CORE_INFO(...)    ::Untold::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UT_CORE_WARN(...)    ::Untold::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UT_CORE_ERROR(...)   ::Untold::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UT_CORE_FATAL(...)   ::Untold::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define UT_TRACE(...)   ::Untold::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UT_INFO(...)    ::Untold::Log::GetClientLogger()->info(__VA_ARGS__)
#define UT_WARN(...)    ::Untold::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UT_ERROR(...)   ::Untold::Log::GetClientLogger()->error(__VA_ARGS__)
#define UT_FATAL(...)   ::Untold::Log::GetClientLogger()->fatal(__VA_ARGS__)

