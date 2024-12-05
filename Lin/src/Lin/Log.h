#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Lin {

	class LIN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//__VA_ARGS__获取宏定义参数
#define LIN_CORE_TRACE(...)			Lin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LIN_CORE_INFO(...)			Lin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LIN_CORE_WARN(...)			Lin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LIN_CORE_ERROR(...)			Lin::Log::GetCoreLogger()->error(__VA_ARGS__) 
#define LIN_CORE_FATAL(...)			Lin::Log::GetCoreLogger()->fatal(__VA_ARGS__) 

#define LIN_TRACE(...)				Lin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LIN_INFO(...)				Lin::Log::GetClientLogger()->info(__VA_ARGS__)
#define LIN_WARN(...)				Lin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LIN_ERROR(...)				Lin::Log::GetClientLogger()->error(__VA_ARGS__) 
#define LIN_FATAL(...)				Lin::Log::GetClientLogger()->fatal(__VA_ARGS__) 