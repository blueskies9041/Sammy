
#ifndef CAMERA_H
#define	CAMERA_H

#include "Misc.h"

class CCamera
{
public:

    CCamera(int a_iWindowWidth, int a_iWindowHeight);
    CCamera(int a_iWindowWidth, int a_iWindowHeight, const glm::vec3& v3Pos,  const glm::vec3& v3Target,  const glm::vec3& v3Up);

    bool OnKeyboard(int Key);

    void OnMouse(int x, int y);

    void OnRender();

    inline const glm::vec3& GetPos() const
    {
        return v3Pos;
    }

    inline const glm::vec3& GetTarget() const
    {
        return v3Target;
    }

    inline const glm::vec3& GetUp() const
    {
        return v3Up;
    }

private:

    void Init();
    void Update();

    glm::vec3 m_v3Pos;
    glm::vec3 m_v3Target;
    glm::vec3 m_v3Up;

    int m_iWindowWidth;
    int m_iWindowHeight;

    float m_fAngleH;
    float m_fAngleV;

    bool m_bOnUpperEdge;
    bool m_bOnLowerEdge;
    bool m_bOnLeftEdge;
    bool m_bOnRightEdge;

    glm::vec3 v2MousePos;
};

#endif	/* CAMERA_H */

