#pragma once

#include <GLFW/glfw3.h>


class fpsCounter
{
	public:
		unsigned int frames = 0;
		double previousTime = glfwGetTime();
		double time = glfwGetTime();

		fpsCounter();

		void update(GLFWwindow* window);
};