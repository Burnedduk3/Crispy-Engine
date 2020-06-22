#pragma once
#include "Application.h"

#ifdef CY_PLATFORM_WINDOWS

extern Crispy::Application* Crispy::CreateApplication();

int main(int argc, char** argv) {
	auto app = Crispy::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Crispy only support windows
#endif // CY_PLATFORM_WINDOWS
