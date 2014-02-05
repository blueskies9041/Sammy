/*
	PROJECT INFORMATION

		Name: SamOGL
		Brief: Beginnings of Samuel Legus's AIE Assessment 4 Project

		* Significant Changes:
			Redid everything.

		* To Do:
				Sprite class improvements
				Text
				UV/Rotation Stuff
				Particle System
				Get/Setters??
				Physics
				Animation
				Engine class
				Particle System

		

	LAST RECORDED EDITS ON: Feb 4, 2014
*/

#include "glew.h"
#include "glfw3.h"
#include "Sprite.h"
#include <iostream>

using namespace std;
/* */

void main() {
	
	/* Window */
	GLFWwindow* MyWindow = Sam::NewWindow();

	/* Test Sprite Object */
	CSprite * Sprite = new CSprite("resources/textures/test.bmp", 128, 128, glm::vec4(0,0,1,1), MyWindow);
	CSprite SpriteB("resources/textures/test.bmp", 128, 128, glm::vec4(0,0,1,1), MyWindow);
	SpriteB.m_v3Position = glm::vec3(100,100,0);

	/* Main Loop */
	while (!glfwWindowShouldClose(MyWindow)) {	
        /* Render loop*/
		Justin::glfw_update_fps_counter(MyWindow);

		glViewport(0,0,Sam::iWindowWidth, Sam::iWindowHeight);
		glClearColor(0.0f, 0.5f, 0.8f, 0.0f);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* DEBUGGING */
		if(glfwGetTime() >= 5) {
			glfwSetTime(0);
			cout << "("<< Sprite->m_v3Position.x << "," << Sprite->m_v3Position.y << ")" << endl;
		}

		Sprite->Input();
		Sprite->Draw();
		SpriteB.Draw();

		if(Sprite->CheckBoxCollision(SpriteB))
			SpriteB.m_v3Position.x *= -1.0f;

        glfwSwapBuffers(MyWindow);

        /* Poll for and process events */
		if(GLFW_PRESS == glfwGetKey(MyWindow, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(MyWindow, true);
		
		glfwPollEvents();
    }

	delete Sprite;
	Sprite->Cleanup();
	SpriteB.Cleanup();

	glfwTerminate();
}

