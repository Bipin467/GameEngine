#shader vertex
#version 330 core

layout(location = 0)in vec4 position;
layout(location = 1)in vec2 texCoord;
uniform mat4 u_MVP=mat4(1.0);
out vec2 v_TexCoord;
//out vec3 v_LightPosition;
//out vec3 v_VertexPosition;
void main()
{
	v_TexCoord = texCoord;
	gl_Position = u_MVP*position;
};

#shader fragment
#version 330 core
layout(location = 0)out vec4 color;
in vec2 v_TexCoord;
uniform vec4 u_Color;
uniform sampler2D u_Texture;
void main()
{
	vec4 texColor = texture(u_Texture,v_TexCoord);
	color = texColor *u_Color;

};