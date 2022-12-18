#pragma once

#include <glad/glad.h>
#include <OpenGLUtility/VBO.h>


class VAO
{
public:
	VAO();
	void bind();
	void setVertexData(
		VBO vbo, 
		GLuint attributeIndex,
		GLint size,
		GLenum type,
		GLboolean normalized,
		GLsizei stride,
		const void* pointer
	);
private:
	unsigned int vao;
};