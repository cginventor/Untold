#include <Untold.h>

class Sandbox : public Untold::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Untold::Application* Untold::CreateApplication()
{
	return new Sandbox();
}