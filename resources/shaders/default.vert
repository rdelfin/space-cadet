#version 400 core

uniform vec3 camera_position;
uniform vec4 light_position = vec4(0.0, 100.0, 20.0, 1.0);

in vec4 vertex_position;
in vec4 normal;


out vec4 vs_normal;
out vec4 vs_camera_direction;
out vec4 vs_light_direction;

void main() {
    gl_Position = vertex_position;
    vs_normal = normal;
    vs_camera_direction = normalize(vec4(camera_position - vec3(gl_Position), 0.0));
    vs_light_direction = normalize(light_position - gl_Position);
}
