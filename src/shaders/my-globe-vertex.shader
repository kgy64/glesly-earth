precision highp float;

uniform mat4 camera_matrix;
uniform mat4 t0_matrix;
uniform mat4 t1_matrix;
uniform mat4 t2_matrix;
uniform mat4 t3_matrix;
uniform mat4 p_matrix;

mat4 my_matrix = camera_matrix * t3_matrix * t2_matrix * t1_matrix * t0_matrix * p_matrix;

attribute vec3 position;
attribute vec4 colour;

varying vec4 frag_colour;

void main()
{
    gl_Position = my_matrix * vec4(position, 1.0);
    frag_colour = colour;
}
