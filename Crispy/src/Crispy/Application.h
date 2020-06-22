#pragma once

#include "Core.h"
namespace Crispy {
	class CRISPY_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}
