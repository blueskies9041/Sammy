#ifndef _MISC_H_
#define _MISC_H_

#include <cstdlib>
#include <algorithm>
#include "glew.h"
#include "glfw3.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

using namespace std;

namespace Justin
{
	//slightly modified by me
	struct Vertex {
		union {
			struct {
				glm::vec3 Pos;
				glm::vec4 Color;
				glm::vec2 UV;
			};
		
			struct {
				float X, Y, Z;
				float R, G, B, A;
				float U, V;
			};
		};
	};

	void glfw_window_size_callback(GLFWwindow* window, int width, int height);
	void glfw_error_callback(int error, const char * description);
	void glfw_update_fps_counter(GLFWwindow* window);
};

namespace Sam
{
	extern int iWindowWidth;
	extern int iWindowHeight;
	extern GLFWwindow * MyWindow;
	extern glm::mat4 m4Projection;

	GLuint LoadTexture(const char *, int, int);
	GLFWwindow* NewWindow();

	inline float Random()
	{
		return rand() / (float)RAND_MAX;
	}

	inline float RandRange( float fMin, float fMax )
	{
		if ( fMin > fMax ) std::swap( fMin, fMax );
		return ( Random() * ( fMax - fMin ) ) + fMin;
	}

	inline glm::vec3 RandUnitVec()
	{
		float x = ( Random() * 2.0f ) - 1.0f;
		float y = ( Random() * 2.0f ) - 1.0f;
		float z = ( Random() * 2.0f ) - 1.0f;

		return glm::normalize( glm::vec3(x,y,z) );
	}

};














/* Accessor Template for possible later Use */
enum Accessor_type { rvalue, lvalue };

template< typename T, Accessor_type = rvalue >
class Accessors;

template< typename T >
class Accessors< T, lvalue > {
private:
	T m_t;
public:
	Accessors< T, lvalue >() {}
	explicit Accessors< T, lvalue >( const T &t ) : m_t( t ) {}

	T &operator() () { return m_t; }
	const T &operator() () const { return m_t; }
};

template< typename T >
class Accessors< T, rvalue > {
private:
	T m_t;
public:
	Accessors< T, rvalue >() {}
	explicit Accessors< T, rvalue >( const T &t ) : m_t( t ) {}

	const T &operator() () const { return m_t; }
	void operator() ( const T &t ) { m_t = t; }
};

#endif