#version 330 core
layout (location = 0) in vec3 positition;

void main()
{
    gl_Position = vec4(positition, 1.0f);
}