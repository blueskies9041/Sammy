#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "Misc.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Assert.h"

// Load a .BMP file using our custom loader
GLuint LoadBMP(const char * imagepath);

// Load a .TGA file using GLFW's own loader
GLuint loadTGA_glfw(const char * imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);

GLuint LoadTexture(const char* a_szTexture, unsigned int a_uiFormat 
					 =GL_RGBA , unsigned int* a_uiWidth  = nullptr , 
					unsigned int* a_uiHeight  = nullptr , unsigned int* a_uiBPP  = nullptr);
#endif