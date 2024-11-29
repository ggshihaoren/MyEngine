#include <Lin.h>

class Sandbox : public Lin::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Lin::Application* Lin::CreateApplication() {
	return new Sandbox();
}