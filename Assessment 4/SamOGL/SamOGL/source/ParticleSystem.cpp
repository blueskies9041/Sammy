#include "ParticleSystem.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;


int g_iMaxParticles = 1000;
double fLastTime = glfwGetTime();

CParticleSystem::CParticleSystem(int a_iWidth, int a_iHeight, int a_iMaxParticles)
: m_iMaxParticles(g_iMaxParticles), m_iWidth(a_iWidth), m_iHeight(a_iHeight) , m_iLastUsedParticle(0) {
	
	//Texture
	m_glTextureID = Sam::LoadTexture("resources/textures/particle.bmp", m_iWidth, m_iHeight);

	//Particle VBO data
	m_glParticleSpaceData = new GLfloat[m_iMaxParticles * 4];
	m_glColorData = new GLubyte[m_iMaxParticles * 4];

	for(int i = 0; i < m_iMaxParticles; ++i) { 
		m_aParticles[i].fLife = -1.0f;
		m_aParticles[i].fCameraDistance = -1.0f;
	}

	//Quad VBO data
	GLfloat a_fQuadVertices[12] = {
		0.0f , m_iHeight, 0.0f,
		m_iWidth , m_iHeight, 0.0f,
		0.0f , 0.0f, 0.0f,
		m_iWidth , 0.0f, 0.0f
	};

	for(int i = 0; i < 12; ++i) 
		m_glQuadData = a_fQuadVertices[i];

	//Quad VAO
	glGenVertexArrays(1, &m_glVAO);
	glBindVertexArray(m_glVAO);

	//Quad VBO
	glGenBuffers(1, &m_glQuadVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_glQuadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(a_fQuadVertices), a_fQuadVertices, GL_STATIC_DRAW);

	//Pos + Speed VBO
	glGenBuffers(1, &m_glSpaceVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_glSpaceVBO);
	glBufferData(GL_ARRAY_BUFFER, m_iMaxParticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);

	//Color VBO
	glGenBuffers(1, &m_glColorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_glColorVBO);
	glBufferData(GL_ARRAY_BUFFER, m_iMaxParticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW);


}

CParticleSystem::~CParticleSystem () {
}

int CParticleSystem::FindUnusedParticle() {

	for(int i = 0; i < m_iMaxParticles; ++i) {
		if(m_aParticles[i].fLife < 0) {
			m_iLastUsedParticle = i;
			return i;
		}
	}

	for(int i = 0; i < m_iLastUsedParticle; ++i) {
		if(m_aParticles[i].fLife < 0) {
			m_iLastUsedParticle = i;
			return i;
		}
	}

	return 0;
}

void CParticleSystem::SortParticles() {
	std::sort(&m_aParticles[0], &m_aParticles[m_iMaxParticles]);
}

void CParticleSystem::Update() {

	//time
	double fCurrentTime = glfwGetTime();
	double fDelta = fCurrentTime - fLastTime;
	fLastTime = fCurrentTime;

	//fps limiter
	int iNewParticles = (int)(fDelta * 10000.0f);

	if (iNewParticles > (int)(0.016f*10000.0))
		iNewParticles = (int)(0.016f*10000.0);

	//Initializing particles
	for(int i = 0 ; i < iNewParticles; ++i) {

		int iParticleIndex = FindUnusedParticle();
		m_aParticles[iParticleIndex].fLife = 5.0f;
		m_aParticles[iParticleIndex].v3Position = glm::vec3(0,0,-20.0f);

		float fSpread = 1.5f;

		glm::vec3 v3MainDir = glm::vec3(0.0f, 10.0f, 0.0f);
		glm::vec3 v3RandomDir = glm::vec3(
			(rand()%2000 - 1000.0f)/1000.0f,
			(rand()%2000 - 1000.0f)/1000.0f,
			(rand()%2000 - 1000.0f)/1000.0f
		);

		m_aParticles[iParticleIndex].v3Speed = v3MainDir * v3RandomDir * fSpread;

		m_aParticles[iParticleIndex].r = rand() % 256;
		m_aParticles[iParticleIndex].g = rand() % 256;
		m_aParticles[iParticleIndex].b = rand() % 256;
		m_aParticles[iParticleIndex].a = (rand() % 256) / 3;

		m_aParticles[iParticleIndex].fSize = (rand()%1000)/2000.0f + 0.1f;
	}

	//Simulating particles
	int iParticleCount = 0;
	for(int i = 0 ; i < m_iMaxParticles; ++i) {

		Particle& p = m_aParticles[i];

		if(p.fLife > 0.0f) {
			//gravity 
			p.v3Speed += glm::vec3(0.0f,-9.81f, 0.0f) * (float)fDelta * 0.5f;
			p.v3Position += p.v3Speed * (float)fDelta;

			// Fill the GPU buffer
			m_glParticleSpaceData[4*iParticleCount+0] = p.v3Position.x;
			m_glParticleSpaceData[4*iParticleCount+1] = p.v3Position.y;
			m_glParticleSpaceData[4*iParticleCount+2] = p.v3Position.z;
												   
			m_glParticleSpaceData[4*iParticleCount+3] = p.fSize;
												   
			m_glColorData[4*iParticleCount+0] = p.r;
			m_glColorData[4*iParticleCount+1] = p.g;
			m_glColorData[4*iParticleCount+2] = p.b;
			m_glColorData[4*iParticleCount+3] = p.a;
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, m_glSpaceVBO);
	glBufferData(GL_ARRAY_BUFFER, m_iMaxParticles * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf.
	glBufferSubData(GL_ARRAY_BUFFER, 0, iParticleCount * sizeof(GLfloat) * 4, m_glParticleSpaceData);

	glBindBuffer(GL_ARRAY_BUFFER, m_glColorVBO);
	glBufferData(GL_ARRAY_BUFFER, m_iMaxParticles * 4 * sizeof(GLubyte), NULL, GL_STREAM_DRAW); // Buffer orphaning, a common way to improve streaming perf. 
	glBufferSubData(GL_ARRAY_BUFFER, 0, iParticleCount * sizeof(GLubyte) * 4, m_glColorData);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


}