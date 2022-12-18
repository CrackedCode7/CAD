#include "VBO.h"


VBO::VBO()
{
	glGenBuffers(1, &vbo);
	bind();
}


void VBO::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
}


void VBO::setData(GLsizeiptr size, const void* data)
{
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}