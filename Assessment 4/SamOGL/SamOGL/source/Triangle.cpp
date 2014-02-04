#include "Triangle.h"

CTriangle::CTriangle(float  * a_afVertices, GLuint &a_ShaderProgram)
{
	for(int i = 0 ; i < 9; ++i)
		m_afVertices[i] = a_afVertices[i];

	m_ShaderProgram = a_ShaderProgram;
	m_VBO = Sam::GetTriangleVBO(m_afVertices);
	m_VAO = Sam::GetTriangleVAO(m_VBO);
}

void CTriangle::Draw()
{
	glUseProgram(m_ShaderProgram);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}