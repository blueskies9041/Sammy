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
#include "Particle.h"
#include <iostream>

using namespace std;
/* */

void main() {
	
	/* Window */
		//Temporarily in Sam namespace for GLFW window variable passing issues with Particle system class

	/* Test Sprite Object */
	//CSprite * Sprite = new CSprite("resources/textures/test.bmp", 128, 128, 512, 368, glm::vec4(0,0,1,1), MyWindow);
	//CSprite SpriteB("resources/textures/test.bmp", 128, 128, 100, 100, glm::vec4(0,0,1,1), MyWindow);
	
	/* Test Particle System Object */

	glm::vec3 force[1] = {glm::vec3(0,1,0)};

	CParticleSystem * P = new CParticleSystem(100, 1, force, Create, glm::vec3(5,5,0), 3, 128, MyWindow);
	/* Main Loop */
	while (!glfwWindowShouldClose(MyWindow)) {	
        /* Render loop*/
		Justin::glfw_update_fps_counter(MyWindow);

		glViewport(0,0,Sam::iWindowWidth, Sam::iWindowHeight);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/* DEBUGGING */
		if(glfwGetTime() >= 5) {
			glfwSetTime(0);
			//cout << "("<< Sprite->m_v3Position.x << "," << Sprite->m_v3Position.y << ")" << endl;
		}

		//Sprite->Input();
		P->Update();
		//Sprite->Draw();
		//SpriteB.Draw();
	
		//if(Sprite->CheckBoxCollision(SpriteB))
		//	SpriteB.m_v3Position.x *= -1.0f;

        glfwSwapBuffers(MyWindow);

        /* Poll for and process events */
		if(GLFW_PRESS == glfwGetKey(MyWindow, GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(MyWindow, true);
		
		glfwPollEvents();
    }

	//Sprite->Cleanup();
	//delete Sprite;
	
	//SpriteB.Cleanup();

	glfwTerminate();
}

