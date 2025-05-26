#version 450 core

uniform vec4 inputColor;
out vec4 fragColor;

void main() {
    fragColor = inputColor;
}