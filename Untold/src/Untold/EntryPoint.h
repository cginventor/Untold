#pragma once

#ifdef UT_PLATFORM_WINDOWS

extern Untold::Application* Untold::CreateApplication();

int main(int argc, char** argv)
{
	Untold::Log::Init();
	UT_CORE_WARN("Initialized Log");
	int a = 5;
	UT_INFO("Hello! Var={0}", a);

	auto app = Untold::CreateApplication();
	app->Run();
	delete app;
}

#endif