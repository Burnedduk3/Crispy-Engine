#pragma once

#ifdef CY_PLATFORM_WINDOWS
#ifdef CY_BUILD_DLL
#define CRISPY_API __declspec(dllexport)
#else
#define CRISPY_API __declspec(dllimport)
#endif // CY
#else
#error Crispy only support windows
#endif // CY_PLATFORM_WINDOWS
