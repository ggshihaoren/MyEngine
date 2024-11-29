#pragma once

#ifdef LIN_PLATFORM_WINDOWS

extern Lin::Application* Lin::CreateApplication();

int main()
{
	printf("111\n");
	auto app = Lin::CreateApplication();
	app->Run();
	delete app;
}

#endif