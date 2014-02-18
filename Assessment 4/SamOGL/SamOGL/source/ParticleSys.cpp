#include "ParticleSys.h"
#include "Shader.h"


CParticleSystem::CParticleSystem() {

	//Shader
	m_glShaderProgram = LoadShaders("resources/shaders/test.vert", "resources/shaders/test.geo", "resources/shaders/test.frag");
	
	//VAO
	glGenVertexArrays(1, &m_glVAO);
	glBindVertexArray(m_glVAO);

	//VBO for Points
	glGenBuffers(1, &m_glVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_glVBO);

	GLfloat afPointsWorld[] = {
		0.0f  , 48.0f, 0.0f,
		48.0f , 48.0f, 0.0f,
		0.0f  , 0.0f , 0.0f,
		48.0f , 0.0f , 0.0f
	};

	GLfloat afPoints[] = {
	/*	POINTS					COLORS						SIDES*/
		-0.45f,  0.45f, 0.0f,	1.0f, 0.0f, 0.0f, 1.0f,		4.0f ,
		0.45f ,  0.45f, 0.0f,	0.0f, 1.0f, 0.0f, 1.0f,		8.0f ,
		-0.45f, -0.45f, 0.0f,	0.0f, 0.0f, 1.0f, 1.0f,		16.0f,
		0.45f , -0.45f, 0.0f,	1.0f, 1.0f, 1.0f, 1.0f,		63.0f, 
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(afPoints), afPoints, GL_STATIC_DRAW);

	//Points attribute
	GLint glPosAttrib = glGetAttribLocation(m_glShaderProgram, "pos");
	glEnableVertexAttribArray(glPosAttrib);
	glVertexAttribPointer(	glPosAttrib,  
							3, //Vec 3 = Size 3
							GL_FLOAT, //variable type
							GL_FALSE, //normalized? 
							8 * sizeof(float), //size of each attribute
							0); //offset

	//Color attribute
	GLint glColorAttrib = glGetAttribLocation(m_glShaderProgram, "color");
	glEnableVertexAttribArray(glColorAttrib);
	glVertexAttribPointer(  glColorAttrib,
							4,
							GL_FLOAT,
							GL_FALSE,
							8 * sizeof(float),
							(void*) (3 * sizeof(float)));

	//Number of sides attribute
	GLint glSidesAttrib = glGetAttribLocation(m_glShaderProgram, "sides");
	glEnableVertexAttribArray(glSidesAttrib);
	glVertexAttribPointer(  glSidesAttrib,
							1,
							GL_FLOAT,
							GL_FALSE,
							8 * sizeof(float),
							(void*) (7 * sizeof(float)));



}

CParticleSystem::~CParticleSystem() {
	glDeleteShader(m_glShaderProgram);
	glDeleteBuffers(1, &m_glVBO);
	glDeleteVertexArrays(1, &m_glVAO);
}

void CParticleSystem::Update() {

	glUseProgram(m_glShaderProgram);
	glDrawArrays(GL_POINTS, 0, 4);

}
