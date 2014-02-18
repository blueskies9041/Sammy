#version 150

layout(points) in;
layout(line_strip, max_vertices = 64) out;

//Geomentry shader must take inputs as arrays because
//gs can recieve primitives with multiple vertices as input, each with 
//its own attribute values

in vec4 vColor[]; //Output from Vertex Shader
in float vSides[];
out vec4 fColor; //Output to Fragment Shader

const float PI = 3.1415926;

void main() {

	fColor = vColor[0];

	for(int i = 0; i <= vSides[0]; i++) {

		float ang = PI * 2.0 / vSides[0] * i;
		vec4 offset = vec4(cos(ang) * 0.3, -sin(ang) * 0.4, 0.0, 0.0);
		gl_Position = gl_in[0].gl_Position + offset;
		EmitVertex();

	}

	EndPrimitive();
}

//draws 4 shapes to the screen