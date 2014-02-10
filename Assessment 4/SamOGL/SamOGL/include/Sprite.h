#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Quad.h"

class CSprite : public CQuad
{
	public:

		glm::vec3 m_v3Position;
		glm::vec3 m_v3Speed;
		glm::vec2 m_v2Scale;
		glm::vec4 m_v4SpriteColor;
		glm::mat4 m_m4Model;
		glm::mat4 m_m4MVP;

		int m_iMatrixLocation;
		int m_iTextureLocation;

		GLuint m_glTextureID;
		GLFWwindow * m_oGameWindow;

		CSprite();
		CSprite( const char* a_cpTexture, int a_iWidth, int a_iHeight, int a_iPosX, int a_iPosY, glm::vec4 a_v4Color , GLFWwindow * a_opWindow);
		~CSprite();

		void Draw();
		void Input();
		void Cleanup();
	
		bool CheckBoxCollision(CSprite &a_roSprite);
};




#endif