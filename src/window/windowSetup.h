#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace window
{
	extern unsigned int SCR_WIDTH;
    extern unsigned int SCR_HEIGHT;

    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);
    bool initializeGLFW();
    GLFWwindow* createWindowAndInitializeGLAD();
}