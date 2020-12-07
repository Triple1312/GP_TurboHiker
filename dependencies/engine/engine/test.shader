#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 aColor;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0f);
    aColor = color;
}

#shader fragment
#version 330 core

out vec4 Fragcolor;
in vec4 aColor;

void main() {
    Fragcolor = aColor;
}