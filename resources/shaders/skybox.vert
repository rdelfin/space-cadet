#version 400 core

in vec4 vertex_position;

out vec3 vertex_tex_coords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    vertex_tex_coords = vec3(vertex_position);
    gl_Position = projection * view * vertex_position;
}
