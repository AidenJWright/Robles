#pragma once

#ifdef RS_PLATFORM_WINDOWS

extern Robles::Application* Robles::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Robles::CreateApplication();
	app->Run();
	delete app;
}

#endif // RS_PLATFORM_WINDOWS
