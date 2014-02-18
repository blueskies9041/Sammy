#ifndef _PARTICLESYS_H_
#define _PARITCLESYS_H_

#include "Misc.h"

struct Particle {
	glm::vec3 v3Position;
	glm::vec3 v3Velocity;
	float fLifetime;
};

class CParticleSystem {

	public:

		CParticleSystem();
		~CParticleSystem();

		GLuint m_glShaderProgram;
		Particle m_aParticles[100];
		GLuint m_glVAO;
		GLuint m_glVBO;

		void Update();
};

#endif