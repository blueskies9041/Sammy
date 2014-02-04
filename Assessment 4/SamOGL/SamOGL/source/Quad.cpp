#include "Quad.h"
#include "Misc.h"
#include "Shader.h"
#include "Texture.h"

CQuad::CQuad() {
}

CQuad::CQuad(glm::vec4 a_v4Color, int a_iWidth, int a_iHeight) : m_iHeight(a_iHeight), m_iWidth(a_iWidth) {

	/* VAO */
	glGenVertexArrays(1, &m_glVAO);
	glBindVertexArray(m_glVAO);

	/* VBO */
	glGenBuffers(1, &m_glVBO);

	m_aoVerts[0].Pos = glm::vec3( 0.0f , m_iHeight, 0.0f);
	m_aoVerts[1].Pos = glm::vec3( m_iWidth , m_iHeight, 0.0f);
	m_aoVerts[2].Pos = glm::vec3( 0.0f , 0.0f, 0.0f);
	m_aoVerts[3].Pos = glm::vec3( m_iWidth , 0.0f, 0.0f);

	m_aoVerts[0].Color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	m_aoVerts[1].Color = glm::vec4(0.0f, 1.0f, 0.01, 1.0f);
	m_aoVerts[2].Color = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	m_aoVerts[3].Color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	m_aoVerts[0].UV = glm::vec2(0.0f, 0.0f);
	m_aoVerts[1].UV = glm::vec2(0.0f, 1.0f);
	m_aoVerts[2].UV = glm::vec2(1.0f, 0.0f);
	m_aoVerts[3].UV = glm::vec2(1.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, m_glVBO);
	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), m_aoVerts , GL_STATIC_DRAW);

	/* EBO  */
	glGenBuffers(1, &m_glEBO);
    GLuint elements[] = {
        0, 1, 2, 3
    };
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_glEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	/* Shader Program */
	m_glShaderProgram = LoadShaders("resources/shaders/basic.vert", "resources/shaders/basic.frag");

	/* Position Attribute*/
	GLint glPosAttrib = glGetAttribLocation(m_glShaderProgram, "position");
	glEnableVertexAttribArray(glPosAttrib);
	glVertexAttribPointer(	glPosAttrib, // name of GL variable
							3, //size of GL variable (3 for vec3)
							GL_FLOAT, //type of variable
							GL_FALSE, //normalized?
							sizeof(Vertex), //CRITICAL: number of bytes between each position attribute xyz rgba uv = 9
							0); //how far from the start of the array the attribute occurs
	/* Color Attribute */
	GLint glColorAttrib = glGetAttribLocation(m_glShaderProgram, "color");
	glEnableVertexAttribArray(glColorAttrib);
	glVertexAttribPointer(	glColorAttrib,
							4, 
							GL_FLOAT,
							GL_FALSE,
							sizeof(Vertex), 
							(void*)(3 * sizeof(float))); 
	/* Texture Attribute */
	GLint glTexAttrib = glGetAttribLocation(m_glShaderProgram, "texcoord");
	glEnableVertexAttribArray(glTexAttrib);
	glVertexAttribPointer(	glTexAttrib, 
							2, 
							GL_FLOAT,
							GL_FALSE, 
							sizeof(Vertex), 
							(void*)(7 * sizeof(float))); //each tex coord is 6 away from start of array
}

CQuad::~CQuad() {
}

