
#version 150

in vec3 pos;
in vec4 color;
in float sides;

out vec4 vColor;
out float vSides;

void main() {
	gl_Position = vec4(pos, 1.0);
	vColor = color;
	vSides = sides;
}

// Forwards position & color