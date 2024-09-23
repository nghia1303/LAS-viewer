#version 330
// uniform sampler2D qt_Texture0;
// varying highp vec4 qt_TexCoord0;
varying lowp vec4 col;
void main(void)
{
    // gl_FragColor = texture2D(qt_Texture0, qt_TexCoord0.st);
		// gl_FragColor = vec4(0.0f, 0.1f, 0.2f, 1.0f);
	gl_FragColor = col;
}
