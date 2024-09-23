#version 330 core
attribute highp vec4 qt_Vertex;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
// attribute highp vec3 qt_Vertex;
// attribute highp vec4 qt_MultiTexCoord0;
// uniform highp mat4 qt_ModelViewProjectionMatrix;
// varying highp vec4 qt_TexCoord0;

void main(void)
{
	col = colAttr;
	gl_Position = vec4(qt_Vertex);
    // qt_TexCoord0 = qt_MultiTexCoord0;
}
