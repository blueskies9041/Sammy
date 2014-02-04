#include "Misc.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Assert.h"
#include "GLLOG.h"

using namespace std;

namespace Justin
{
	void glfw_window_size_callback(GLFWwindow* window, int width, int height)
	{
		Sam::iWindowWidth = width;
		Sam::iWindowHeight = height;
	}
	void glfw_error_callback(int error, const char * description)
	{
		fputs(description, stderr);
		gl_log(description, __FILE__, __LINE__);
		//update matrices below
	}
	void glfw_update_fps_counter(GLFWwindow* window)
	{
		static double previous_seconds = glfwGetTime();
		static int frame_count;
		double current_seconds = glfwGetTime();
		double elapsed_seconds = current_seconds - previous_seconds;
		if(elapsed_seconds > .25)
		{
			previous_seconds = current_seconds;
			double fps = (double)frame_count / elapsed_seconds;
			char tmp[128];
			sprintf(tmp, "OpenGL @ FPS %.2f", fps);
			glfwSetWindowTitle(window, tmp);
			frame_count = 0;
		}
		frame_count++;
	}
};

namespace Sam
{
	int iWindowWidth = 1024;
	int iWindowHeight = 768;

	glm::mat4 m4Projection = glm::ortho(0.0f,1024.0f,768.0f,0.0f,0.0f,1.0f);
	
	GLFWwindow* NewWindow()
	{
		glfwInit();

		char message[256];
		sprintf(message, "Starting GLFW %s\n", glfwGetVersionString());
		assert(gl_log(message, __FILE__, __LINE__));
		glfwSetErrorCallback(Justin::glfw_error_callback);

		glfwWindowHint(GLFW_SAMPLES, 16);
		//Fullscreen mode stuff
		GLFWmonitor* mon = glfwGetPrimaryMonitor();

		const GLFWvidmode* vmode = glfwGetVideoMode(mon);
		GLFWwindow* MyWindow = glfwCreateWindow(vmode ->width, vmode->height, "FUCK YYEAAAHHHHH AUSTRALIA", NULL, NULL);

		glfwSetWindowSize(MyWindow, iWindowWidth, iWindowHeight);
		glfwMakeContextCurrent(MyWindow);

		if(!MyWindow)
		{
			fprintf( stderr, "ERROR: Could not open GLFW3 Window\n");
			glfwTerminate();
		}

		glfwMakeContextCurrent(MyWindow);

		glewExperimental = GL_TRUE;
		glewInit();

		const GLubyte* renderer = glGetString(GL_RENDERER);
		const GLubyte* version = glGetString(GL_VERSION);
		printf ("Renderer: %s\n", renderer);
		printf( "OpenGL Version: %s\n\n", version);

		//glEnable (GL_DEPTH_TEST);
		//glDepthFunc (GL_LESS);

		return MyWindow;
		}

};


