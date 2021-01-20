#shader vertex
#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 tex_coord;

out vec2 v_TexCoord;

void main() {
    gl_Position = position;
    v_TexCoord = tex_coord;
}

#shader fragment
#version 330 core

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main() {
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor;
}