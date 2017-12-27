#version 400 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

in vec4 vs_camera_direction[];
in vec4 vs_normal[];
in vec4 vs_light_direction[];

out vec4 camera_direction;
out vec4 vertex_normal;
out vec4 world_position;
out vec4 light_direction;

void main() {
    int n = 0;

    for(n = 0; n < gl_in.length(); n++) {
        camera_direction = vs_camera_direction[n];
        light_direction = vs_light_direction[n];
        vertex_normal = model * vs_normal[n];
        gl_Position = projection * view * model * gl_in[n].gl_Position;
        world_position = model * gl_in[n].gl_Position;
        EmitVertex();
    }

    EndPrimitive();
}
