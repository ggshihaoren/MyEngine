#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Lin {
	class LIN_API Application
	{
	public:
		Application();
		~Application();
		void Run();
	};

	Application* CreateApplication();
}

