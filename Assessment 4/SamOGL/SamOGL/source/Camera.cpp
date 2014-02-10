#include "Camera.h"

CCamera::CCamera(int a_iWindowWidth, int a_iWindowHeight) {

	m_iWindowWidth   = a_iWindowWidth;
    m_iWindowHeight  = a_iWindowHeight;
    m_v3Pos          = glm::vec3(0.0f, 0.0f, 0.0f);
    m_v3Target       = glm::vec3(0.0f, 0.0f, 1.0f);
    m_v3Target       = glm::normalize(m_v3Target);
    m_v3Up           = Vector3f(0.0f, 1.0f, 0.0f);

    Init();

}

CCamera::CCamera(int a_iWindowWidth, int a_iWindowHeight, const glm::vec3& a_v3Pos,  const glm::vec3& a_v3Target,  const glm::vec3& a_v3Up) {

	m_iWindowWidth   = a_iWindowWidth;
    m_iWindowHeight  = a_iWindowHeight;

    m_v3Pos          = a_v3Pos
    m_v3Target       = a_v3Target

    m_v3Target       = glm::normalize(m_v3Target);
    m_v3Up           = a_v3Up;
	m_v3Up           = glm::normalize(m_v3Up);

    Init();
}
