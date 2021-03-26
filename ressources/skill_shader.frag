#version 120
uniform sampler2D currentTexture;
uniform float time;

void main(void)
{
    vec2 position = gl_TexCoord[0].xy;
    float factor = 0.08 * cos(2. * time);
    position.x = (position.x + factor) / (1. + 2. * factor);
    position.y = (position.y + factor) / (1. + 2. * factor);

    float brightness = 0.1 + 0.1 * cos(2 * time);
    vec4 pixel_color = texture2D(currentTexture, position);
    pixel_color.x += brightness;
    pixel_color.y += brightness;

    gl_FragColor = pixel_color;
}
