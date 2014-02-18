#version 150

in vec3 position;
in vec4 color;
in vec2 texcoord;
out vec4 Color;
out vec2 Texcoord;
uniform mat4 MVP;

void main()
{
	Color = color;
	Texcoord = texcoord;
    gl_Position = MVP * vec4(position, 1.0);
}

