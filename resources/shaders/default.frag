#version 400 core
#line 1

in vec4 vertex_normal;
in vec4 camera_direction;
in vec4 world_position;
in vec4 light_direction;

uniform vec3 texcolor = vec3(1.0, 1.0, 1.0);
uniform vec3 diffuse = vec3(0.50, 0.50, 0.50);
uniform vec3 ambient = vec3(0.14, 0.14, 0.14);
uniform vec3 specular = vec3(1.00, 1.00, 1.00);
uniform float alpha = 1.0;
uniform float shininess = 1.0;

out vec4 vertex_color;

void main() {
    float dot_nl = dot(light_direction, normalize(vertex_normal));
    dot_nl = clamp(dot_nl, 0.0, 1.0);
    vec3 spec = specular * max(0.0, dot(reflect(-light_direction, vertex_normal), camera_direction));
    vec3 color = clamp(ambient + dot_nl*diffuse/* + spec*/, 0.0, 1.0);
    vertex_color = vec4(color, alpha);
}
