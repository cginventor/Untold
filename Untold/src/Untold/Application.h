#pragma once

#include "Untold/Core.h"
#include "Events/Event.h"

namespace Untold {

	class UNTOLD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();
}


