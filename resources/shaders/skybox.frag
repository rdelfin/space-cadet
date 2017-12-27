#version 400 core
out vec4 vertex_color;

in vec3 TexCoords;

uniform samplerCube skybox;

void main()
{
    vertex_color = texture(skybox, TexCoords);
}
