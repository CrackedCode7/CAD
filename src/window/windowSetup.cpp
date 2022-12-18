#include "windowSetup.h"

#include <iostream>


unsigned int window::SCR_WIDTH = 960;
unsigned int window::SCR_HEIGHT = 640;


void window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// Resize viewport to match new window size
	glViewport(0, 0, width, height);

	window::SCR_WIDTH = width;
	window::SCR_HEIGHT = height;
}


void window::processInput(GLFWwindow* window)
{
	// Do nothing for now
}


bool window::initializeGLFW()
{
	// Initialize GLFW
	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return false;
	}

	// Set up versions
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return true;
}


GLFWwindow* window::createWindowAndInitializeGLAD()
{
	// Initialize GLFW and versions
	if (!window::initializeGLFW())
	{
		std::cout << "Failed to initialize GLFW" << std::endl;
		return NULL;
	}

	// Create glfw Window
	GLFWwindow* window = glfwCreateWindow(window::SCR_WIDTH, window::SCR_HEIGHT, "OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(0);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return NULL;
	}
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	return window;
}