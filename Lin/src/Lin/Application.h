#pragma once

#include "Core.h"

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

