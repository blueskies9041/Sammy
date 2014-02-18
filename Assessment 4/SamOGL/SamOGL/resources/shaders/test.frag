#version 150

in vec4 fColor;
out vec4 outColor;

void main() {
	outColor = fColor;
}

// Takes color value from geometry shader and colors primitives accordingly