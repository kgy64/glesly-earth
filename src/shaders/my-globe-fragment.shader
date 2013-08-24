precision highp float;

uniform sampler2D texture;
varying vec2 frag_texcoord;

void main()
{
    gl_FragColor = texture2D(texture, frag_texcoord);
}
