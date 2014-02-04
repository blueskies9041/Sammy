#ifndef _QUAD_H_
#define _QUAD_H_

#include "Misc.h"
#include "Shader.h"

using namespace Sam;
using namespace Justin;

class CQuad {

	public:

		int m_iWidth;
		int m_iHeight;

		GLuint m_glShaderProgram;
		GLuint m_glVBO;
		GLuint m_glEBO;
		GLuint m_glVAO;

		Vertex m_aoVerts[4];

		CQuad();
		CQuad(glm::vec4 a_v4Color, int a_iWidth, int a_iHeight) ;
		~CQuad();
};
#endif