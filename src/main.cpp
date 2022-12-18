#include <iostream>
#include <vector>

#include <glad/glad.h> // technically do not need here
#include <GLFW/glfw3.h> // technically do not need here
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <window/windowSetup.h>
#include <shaders/Shader.h>
#include <fpsCounter/fpsCounter.h>
#include <OpenGLUtility/VAO.h>
#include <OpenGLUtility/VBO.h>


int main()
{
	// Set up GLFW and GLAD, create window
	GLFWwindow* window = window::createWindowAndInitializeGLAD();
	if (!window)
	{
		return -1;
	}

	// Set up projections
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);

	// Define triangle vertices
	std::vector<float> vertices = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	// Define triangle colors
	std::vector<float> colors = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	// Create VAO to store data
	VAO vao;
	vao.bind();

	// Create a VBO to store vertex data
	VBO vertexVBO;
	vertexVBO.bind();
	vertexVBO.setData(vertices.size() * sizeof(float), vertices.data());

	// Set the vertex data to be used when rendering
	vao.setVertexData(vertexVBO, 0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Create a VBO to store color data
	VBO colorVBO;
	colorVBO.bind();
	colorVBO.setData(colors.size() * sizeof(float), colors.data());
	
	// Set the vertex data to be used when rendering
	vao.setVertexData(colorVBO, 1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Set up shader program
	Shader shader("src/shaders/2DTriangles.vs", "src/shaders/2DTriangles.fs");
	shader.use();
	shader.setMat4("projection", projection);
	shader.setMat4("view", view);
	shader.setMat4("model", model);

	// Main loop
	fpsCounter frameCounter;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Update framerate
		frameCounter.update(window);

		// Activate shader
		shader.use();

		// Specify region to draw in
		//glViewport(0, 0, (int)window::SCR_WIDTH/2, (int)window::SCR_HEIGHT/2);

		// Draw
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}