#include <Crispy.h>

class Sandbox : public Crispy::Application {
public:
	Sandbox() {
	}
	~Sandbox() {
	}
};

Crispy::Application* Crispy::CreateApplication() {
	return new Sandbox();
}