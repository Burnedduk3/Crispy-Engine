#pragma once
#include "Application.h"

#ifdef CY_PLATFORM_WINDOWS

extern Crispy::Application* Crispy::CreateApplication();

int main(int argc, char** argv) {
	Crispy::Log::Init();
	Crispy::Log::GetClientLogger()->info("Initialized Log Client");
	CY_CORE_ERROR_("Initialized Log");
	int a = 10;
	CY_CLIENT_INFO_("Hello var = {0} ", a);
	auto app = Crispy::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Crispy only support windows
#endif // CY_PLATFORM_WINDOWS
