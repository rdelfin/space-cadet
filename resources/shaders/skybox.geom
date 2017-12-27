#version 400 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec3 vertex_tex_coords[];

out vec3 TexCoords;

void main() {
    int n = 0;

    for(n = 0; n < gl_in.length(); n++) {
        gl_Position = gl_in[n].gl_Position;
        TexCoords = vertex_tex_coords[n];
        EmitVertex();
    }

    EndPrimitive();
}

