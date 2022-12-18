#pragma once

#include <glad/glad.h>


class VBO
{
public:
	VBO();
	void bind();
	void setData(GLsizeiptr size, const void* data);
private:
	unsigned int vbo;
};