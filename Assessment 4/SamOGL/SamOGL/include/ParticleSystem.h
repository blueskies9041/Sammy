#ifndef _PARTICLESYSTEM_H_
#define _PARTICLTESYSTEM_H_

#include "Misc.h"
#include <vector>
#include <Algorithm>

using Justin::Vertex;

struct Particle{
	glm::vec3 v3Position, v3Speed;
	unsigned char r,g,b,a; // Color
	float fSize, fAngle, fWeight;
	float fLife; // Remaining life of the particle. if <0 : dead and unused.
	float fCameraDistance;

	bool operator<(const Particle& that) const {
		// Sort in reverse order : far particles drawn first.
		return this->fCameraDistance > that.fCameraDistance;
	}
};

class CParticleSystem {

	public:
		//data

		Particle m_aParticles[1000];
		int m_iMaxParticles;
		int m_iLastUsedParticle;
		int m_iWidth;
		int m_iHeight;
		glm::mat4 m_m4Model;
		
		GLfloat * m_glParticleSpaceData;
		GLubyte * m_glColorData;
		GLfloat  m_glQuadData;

		GLuint m_glShaderProgram;
		GLuint m_glQuadVBO;
		GLuint m_glSpaceVBO;
		GLuint m_glColorVBO;
		GLuint m_glEBO;
		GLuint m_glVAO;
		GLuint m_glTextureID;
		
		//functions

		CParticleSystem(int a_iWidth, int a_iHeight, int a_iMaxParticles);
		~CParticleSystem();

		void SortParticles();
		int FindUnusedParticle();
		void Update();
};




#endif