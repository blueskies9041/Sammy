#include "AppWindow.h"
#include "Misc.h"
#include <stdio.h>

CWindow::CWindow(int a_iWidth, int a_iHeight) : m_iWidth(a_iWidth) , m_iHeight(a_iHeight), m_iRunning(true)
{
	Init();
}

//void CWindow::Init()
//{
//	if (!glfwInit())
//        return;
//
//	m_oWindow = glfwCreateWindow(m_iWidth, m_iHeight, "FUCK YEAH AUSTRALIA", NULL, NULL);
//	if(!m_oWindow)
//	{
//		fprintf( stderr, "ERROR: Could not open GLFW3 Window\n");
//		glfwTerminate();
//		return;
//	}
//
//	glfwMakeContextCurrent(m_oWindow);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	const GLubyte* renderer = glGetString(GL_RENDERER);
//	const GLubyte* version = glGetString(GL_VERSION);
//	printf ("Renderer: %s\n", renderer);
//	printf( "OpenGL Version: %s\n", version);
//
//	glEnable (GL_DEPTH_TEST);
//	glDepthFunc (GL_LESS);
//
//	//Organize later...
//	//Sam::InitTriangle();
//	//Sam::InitShaders();
//	float afPoints[] =
//	{
//		0.0f, 0.5f, 0.0f,
//		0.5f, -0.5f, 0.0f,
//		-0.5f, -0.5f, 0.0f
//	};
//
//	GLuint VBO = 0;
//	glGenBuffers(1, &VBO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof (float), afPoints, GL_STATIC_DRAW);
//	
//	GLuint VAO = 0;
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte *)NULL);
//
//	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vs, 1, &Sam::vertex_shader, NULL);
//	glCompileShader(vs);
//	
//	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fs, 1, &Sam::fragment_shader, NULL);
//	glCompileShader(fs);
//
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader( shaderProgram, fs);
//	glAttachShader( shaderProgram, vs);
//	glLinkProgram(shaderProgram);
//	
//}

void CWindow::Update()
{
	while (!glfwWindowShouldClose(m_oWindow))
    {
        /* Render here */

        /* Swap front and back buffers */
        glfwSwapBuffers(m_oWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

	m_iRunning = false;
    glfwTerminate();
}
