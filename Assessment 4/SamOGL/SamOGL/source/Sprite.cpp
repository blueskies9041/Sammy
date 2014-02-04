#include "Sprite.h"
#include "SOIL.h"

CSprite::CSprite( const char* a_cpTexture, int a_iWidth, int a_iHeight, glm::vec4 a_v4Color , GLFWwindow * a_opWindow) 
: CQuad(glm::vec4(a_v4Color) , a_iWidth, a_iHeight) {

	m_oGameWindow = a_opWindow; // Pass in the App Window for glfw stuff

	/* Position Related Initialization */

	m_v3Position = glm::vec3(512.0f, 384.0f, 0.0f);
	m_v3Speed = glm::vec3(0.0f, 0.0f, 0.0f);
	m_v2Scale = glm::vec2(1.0f, 1.0f);
	m_v4SpriteColor = a_v4Color;
	m_m4Model = glm::mat4(1.0f);
	
	m_iMatrixLocation = glGetUniformLocation(m_glShaderProgram, "trans");

	/* Texture Related Initialization */
	glGenTextures(1, &m_glTextureID);
	glActiveTexture(GL_TEXTURE0);

	//SOIL (external lib) texture loading
	unsigned char* image = SOIL_load_image(a_cpTexture, &a_iWidth, &a_iHeight, 0, SOIL_LOAD_RGBA);
	glBindTexture( GL_TEXTURE_2D, m_glTextureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, a_iWidth, a_iHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	m_iTextureLocation = glGetUniformLocation(m_glShaderProgram, "tex");
}

CSprite::~CSprite(){
}

void CSprite::Draw() {

	glUseProgram(m_glShaderProgram);
	glUniform1i(m_iTextureLocation, 0);

	//Input();
	m_m4Model = glm::translate(glm::mat4(1.0f), m_v3Position); //Update model matrix according to position vector
	m_m4MVP = m4Projection * m_m4Model;
	
	glUniformMatrix4fv( m_iMatrixLocation,
						1,
						GL_FALSE,
						glm::value_ptr(m_m4MVP)); //have to use glm::value_ptr with glm

	glDrawElements(GL_TRIANGLE_STRIP, 4 , GL_UNSIGNED_INT, 0); //draw
	
}

void CSprite::Input() {

	m_v3Speed = glm::vec3(0.0f, 0.0f, 0.0f);

	if (GLFW_PRESS == glfwGetKey(m_oGameWindow, GLFW_KEY_W))
		m_v3Speed.y -= 1.0f;
		
    if (GLFW_PRESS == glfwGetKey(m_oGameWindow, GLFW_KEY_A))
        m_v3Speed.x -= 1.0f;

    if (GLFW_PRESS == glfwGetKey(m_oGameWindow, GLFW_KEY_S))
		m_v3Speed.y += 1.0f;

    if (GLFW_PRESS == glfwGetKey(m_oGameWindow, GLFW_KEY_D))
        m_v3Speed.x += 1.0f;

	m_v3Position += m_v3Speed;
}

bool CSprite::CheckBoxCollision(CSprite &a_roSprite) {
	glm::vec3 v3Source = m_v3Position;
	glm::vec3 v3Target = a_roSprite.m_v3Position;

	return (abs(v3Source.x - v3Target.x) * 2) <  (m_iWidth + a_roSprite.m_iWidth)
		&& (abs(v3Source.y - v3Target.y) * 2) <  (m_iHeight + a_roSprite.m_iHeight);
}

void CSprite::Cleanup() {
	glDeleteTextures(1, &m_glTextureID);
	glDeleteShader(m_glShaderProgram);
	glDeleteBuffers(1, &m_glVBO);
	glDeleteBuffers(1, &m_glEBO);
	glDeleteVertexArrays(1, &m_glVAO);
}