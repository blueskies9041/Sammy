#ifndef CONTROLS_H_
#define CONTROLS_H_

#include "Misc.h"


void ComputeMatricesFromInputs(GLFWwindow* window);
void OnScroll();
glm::mat4 GetViewMatrix();
glm::mat4 GetProjectionMatrix();

#endif;