#pragma once

namespace wls
{
	void Trace(const char * msg, ...);

	void Error(const char* fileName, const char* funcName, int line, const char* msg, ...);
	void Error(const char* fileName, const char* funcName, int line, int code, const char* msg, ...);

	void Setup();
	void Cleanup();

	void EnableTrace(bool enable);
}

#define NET_TRACE(msg, ...) wls::Trace(msg, __VA_ARGS__);
#define NET_ERROR_MSG(msg, ...) wls::Error(__FILE__, __FUNCTION__, __LINE__, msg, __VA_ARGS__);
#define NET_ERROR_CODE(code, msg, ...) wls::Error(__FILE__, __FUNCTION__, __LINE__, code, msg, __VA_ARGS__);
