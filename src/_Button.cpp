#include "_Button.h"
#include <iostream>

_Button::_Button(float x, float y, float width, float height, std::string label, char* textureFile)
    : x(x), y(y), width(width), height(height), label(label)
{
    std::cout << "Creating button: " << label << " with texture: " << textureFile << std::endl;
    texture = new _TextureLoader();

    // Convert std::string to char* using const_cast for compatibility with loadTexture method
    // The loadTexture method requires a char* parameter, but std::string::c_str() returns a const char*.
    // Using const_cast<char*> to safely remove const-ness for compatibility.
    texture->loadTexture(textureFile); // load button texture
    std::cout << "Button created: " << label << std::endl;
}

_Button::~_Button()
{
    //dtor
    std::cout << "Destroying button: " << label << std::endl;
    delete texture;
    std::cout << "Button destroyed: " << label << std::endl;
}

void _Button::drawButton()
{
    // bind button texture
    //std::cout << "Binding texture..." << std::endl;
    texture->bindTexture();
    //std::cout << "Texture bound. Drawing button..." << std::endl;

    glColor3f(1.0, 1.0, 1.0); // keep original color

    // Draw button rectangle
    /* watchout for Z value */
    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(x , y, -1.0); // bot-left
        glTexCoord2f(1.0, 0.0); glVertex3f(x + width , y, -1.0); // bot-right
        glTexCoord2f(1.0, 1.0); glVertex3f(x + width , y - height, -1.0); // top-right
        glTexCoord2f(0.0, 1.0); glVertex3f(x , y - height, -1.0); // top-left
    glEnd();

    // Draw button label
    glColor3f(0.0f, 0.0f, 0.0f); // text color
    glRasterPos3f(x + width / 2 - 0.1f, y - height / 2 + 0.05f, -1.0f); // center the text, + 0.1

    // Check if font rendering is enabled
    std::cout << "Rendering label: " << label << " at position (" << x + width / 2 - 0.1f << ", " << y - height / 2 + 0.05f << ", -1.0)" << std::endl;

    for (char c : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

bool _Button::isClicked(int mouseX, int mouseY)
{
    // Debug: Print button boundaries and mouse coordinates
    std::cout << "Button " << label << " boundaries: (" << x << ", " << y << ", " << x + width << ", " << y - height << ")" << std::endl; std::cout << "Mouse coordinates: (" << mouseX << ", " << mouseY << ")" << std::endl;
    std::cout << "Mouse coordinates: (" << mouseX << ", " << mouseY << ")" << std::endl;
    return (mouseX >= x && mouseX <= x) + (width && mouseY) >= (y && mouseY) <= (y + height);
}
