#pragma once

#ifdef UT_PLATFORM_WINDOWS

extern Untold::Application* Untold::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Untold::CreateApplication();
	app->Run();
	delete app;
}

#endif