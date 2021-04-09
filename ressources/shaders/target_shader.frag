#version 120
uniform sampler2D currentTexture;
uniform float time;

void main()
{
    vec2 coord = gl_TexCoord[0].xy;
    coord.y += cos(radians(3000 * time + coord.y * 10)) * 0.1;
    vec4 pixel_color = texture2D(currentTexture, coord);

    gl_FragColor = pixel_color;
}