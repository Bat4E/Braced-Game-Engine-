#include <iostream>
#include "_LandingPage.h"

_LandingPage::_LandingPage()
{
    //ctor
    texture = new _TextureLoader();
}

_LandingPage::~_LandingPage()
{
    //dtor
    delete texture;
}

void _LandingPage::initLandingPage(char* fileName)
{
    texture->loadTexture(fileName);
}

void _LandingPage::drawLandingPage(int windowWidth, int windowHeight)
{
    //std::cout << "Drawing LandingPage" << std::endl;
    //std::cout << "Window Width: " << windowWidth << ", Window Height: " << windowHeight << std::endl;
    //std::cout << "Image Width: " << texture->width << ", Image Height: " << texture->height << std::endl;

    // Calculate the aspect ratios of the window and the image
    float windowAspectRatio = (float)windowWidth / windowHeight;
    float imageAspectRatio = (float)texture->width / texture->height;

    float scaleX = 1.5;
    float scaleY = 1.0;
    float zValue = -1.5;

    // adjust scaling factors based on aspect ratios
    if (windowAspectRatio > imageAspectRatio)
    {
        // window is wider than image, scale down height
        scaleX = (float)imageAspectRatio / windowAspectRatio;
    }
    else
    {
        // window is taller than the image, scale down height
        scaleY = (float)windowAspectRatio / imageAspectRatio;
    }

    // Debugging values to verify correct calculations
    //std::cout << "After if stmt: Window Width: " << windowWidth << ", Window Height: " << windowHeight << std::endl;
    //std::cout << "After if stmt: Image Width: " << texture->width <<  ", Image Height: " << texture->height << std::endl;
    //std::cout << "After if stmt: Scale X: " << scaleX << ", Scale Y: " << scaleY << std::endl;


    // set color for rendering (white to preserve texture color)
    glColor3f(1.0, 1.0, 1.0);

    // bind texture for rendering
    texture->bindTexture(); // any geometry shape after this, it will bind to it.

    // disable lighting to ensure texture color is not affected
    glDisable(GL_LIGHTING);

    // draw a quad (rectangle) with the texture mapped onto it
    glBegin(GL_QUADS);

    // Debugging texture and vertex coordinates
    //std::cout << "Texture Coordinates and Vertex Coordinates:" << std::endl;

        //std::cout << "TexCoord: (0.0, 0.0), Vertex: (" << -scaleX << ", " << scaleY << ", " << zValue << ")" << std::endl;
        glTexCoord2f(0.0, 0.0); glVertex3f(-scaleX, scaleY, zValue); // bot-left

        //std::cout << "TexCoord: (1.0, 0.0), Vertex: (" << scaleX << ", " << scaleY << ", " << zValue << ")" << std::endl;
        glTexCoord2f(1.0, 0.0); glVertex3f(scaleX, scaleY, zValue); // bot-right

        //std::cout << "TexCoord: (1.0, 1.0), Vertex: (" << scaleX << ", " << -scaleY << ", " << zValue << ")" << std::endl;
        glTexCoord2f(1.0, 1.0); glVertex3f(scaleX, -scaleY, zValue); // top-right

        //std::cout << "TexCoord: (0.0, 1.0), Vertex: (" << -scaleX << ", " << -scaleY << ", " << zValue << ")" << std::endl;
        glTexCoord2f(0.0, 1.0); glVertex3f(-scaleX, -scaleY, zValue); // top-left

    glEnd();
    //std::cout << "LandingPage Quad drawn successfully." << std::endl;

    // re-enable lighting
    glEnable(GL_LIGHTING);
}
