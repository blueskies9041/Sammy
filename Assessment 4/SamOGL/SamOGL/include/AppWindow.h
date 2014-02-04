#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "glew.h"
#include "glfw3.h"

class CWindow
{
private:

		const int m_iWidth;
		const int m_iHeight;
		bool m_iRunning;
		GLFWwindow* m_oWindow;

	public:

	/*
		FUNCTION: Constructor
		PARAMS: int width, int height
		BRIEF: CWindow Class constructor, sets width & height to params, sets running flag to true
	*/
		CWindow(int a_iWidth, int a_iHeight);
	/*
		FUNCTION: Init()
		RETURN: void
		PARAMS:
		BRIEF: 
			Initialzes glfw. 
			Sets up GLFW Window. 
			Returns -1 (error) if glfw isn't initialized or the window couldn't be opened for some reason.
			Makes the Window the current context. (Brings it forward) 
			Enables glewExperimental & Initializes glew.
			Prints GPU name and OGL version to console. 
			Tells OpenGL to only draw onto a pixel if the shape is closer to the viewer (glEnable...) .
			Enables depth testing (gl_DEPTH_TEST) .
	*/
		void Init();
	/*
		FUNCTION: Update()
		RETURN: void
		PARAMS:
		BRIEF: Window update function...
			Loop - Renders and updates GLFW Window.
			Sets running flag to false and terminates glfw when the loop breaks.
			
	*/
		void Update();

	/* Getters and Setters */
		inline bool GetRunning()
		{
			return m_iRunning;
		}
		
};

#endif

//function header template

/*
	FUNCTION:
	RETURN:
	PARAMS:
	BRIEF:
*/