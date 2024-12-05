#pragma once

#ifdef LIN_PLATFORM_WINDOWS

extern Lin::Application* Lin::CreateApplication();

int main(int argc, char** argv)
{
	Lin::Log::Init();
	LIN_INFO("Initialize Client log.\n");
	LIN_CORE_TRACE("Initial Core trace.\n");

	auto app = Lin::CreateApplication();
	app->Run();
	delete app;
}

#endif