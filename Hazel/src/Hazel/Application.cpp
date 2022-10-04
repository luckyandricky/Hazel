#include "Application.h"
#include "stdio.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"
namespace Hazel {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {

		WindowResizeEvent e(1200, 720);
		HZ_TRACE(e);
		printf("hello my");
		while (true);
	}
}
