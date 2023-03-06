#pragma once

#ifdef RS_PLATFORM_WINDOWS

extern Robles::Application* Robles::CreateApplication();

int main(int argc, char** argv)
{
	Robles::Log::Init();
	RS_CORE_WARN("Initialized Log");
	int a = 5;
	RS_CORE_INFO("I'm misc vars Var={0}", a);
	auto app = Robles::CreateApplication();
	app->Run();
	delete app;
}

#endif // RS_PLATFORM_WINDOWS
