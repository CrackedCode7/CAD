#include "fpsCounter.h"

#include <string>


fpsCounter::fpsCounter()
{

}


void fpsCounter::update(GLFWwindow* window)
{
	this->frames++;
	this->time = glfwGetTime();

	if (this->time - this->previousTime >= 1)
	{
		glfwSetWindowTitle(window, std::to_string(frames).c_str());
		this->previousTime = glfwGetTime();
		this->frames = 0;
	}
}