#include <Robles.h>

class App : public Robles::Application
{
public:
	App() {}
	~App() {}
};

Robles::Application* Robles::CreateApplication()
{
	return new App();
}