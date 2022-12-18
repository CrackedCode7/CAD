#include "VAO.h"


VAO::VAO()
{
	glGenVertexArrays(1, &vao);
	bind();
}


void VAO::bind()
{
	glBindVertexArray(vao);
}


void VAO::setVertexData(
	VBO vbo,
	GLuint attributeIndex,
	GLint size,
	GLenum type,
	GLboolean normalized,
	GLsizei stride,
	const void* pointer
)
{
	bind();
	vbo.bind();
	glVertexAttribPointer(
		attributeIndex,
		size,
		type,
		normalized,
		stride,
		pointer
	);
	glEnableVertexAttribArray(attributeIndex);
}