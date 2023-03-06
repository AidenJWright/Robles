#pragma once

#include "Core.h"

namespace Robles {
	class ROBLES_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

