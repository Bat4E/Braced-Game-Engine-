#include "_HelpPage.h"
#include <iostream>

_HelpPage::_HelpPage()
{
    //ctor
    texture = new _TextureLoader();
}

_HelpPage::~_HelpPage()
{
    //dtor
    delete texture;
}

void _HelpPage::initHelpPage(char* fileName)
{
    texture->loadTexture(fileName);
}

void _HelpPage::drawHelpPage(int windowWidth, int windowHeight)
{
    float windowAspectRatio = (float)windowWidth / windowHeight;
    float imageAspectRatio = (float)texture->width / texture->height;

    float scaleX = 1.1;
    float scaleY = 1.0;
    float zValue = -1.4;

    if (windowAspectRatio > imageAspectRatio)
    {
        scaleX = imageAspectRatio / windowAspectRatio;
    }
    else
    {
        scaleY = windowAspectRatio / imageAspectRatio;
    }

    glColor3f(1.0, 1.0, 1.0);

    texture->bindTexture();

    glDisable(GL_LIGHTING);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(-scaleX, scaleY, zValue); // bot-left
        glTexCoord2f(1.0, 0.0); glVertex3f(scaleX, scaleY, zValue); // bot-right
        glTexCoord2f(1.0, 1.0); glVertex3f(scaleX, -scaleY, zValue); // top-right
        glTexCoord2f(0.0, 1.0); glVertex3f(-scaleX, -scaleY, zValue); // top-left
    glEnd();

    // Save current matrices and set up orthographic projection for text rendering
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    // Temporarily disable depth testing
    glDisable(GL_DEPTH_TEST);

    // Change text color to white
    glColor3f(1.0f, 1.0f, 1.0f);
    const char* helpText = "Help Instructions:\n- Use arrow keys to move\n- Press space to shoot\n- Press Escape to return to the Menu Page";
    float lineSpacing = 20.0f; // Adjust line spacing for orthographic projection
    float xPos = 10.0f;
    float yPos = windowHeight - 30.0f; // start from the top
    //float zPos = -1.0f;

    // Debug: Check if text rendering functions are called
    //std::cout << "Setting raster position to (" << xPos << ", " << yPos << ", " << zValue << ")" << std::endl;

    glRasterPos2f(xPos, yPos);

    for (const char* c = helpText; *c != '\0'; c++) {
        if (*c == '\n') {
            yPos -= lineSpacing;
            //std::cout << "New line: setting raster position to (" << xPos << ", " << yPos << ")" << std::endl;
            glRasterPos2f(xPos, yPos); // adjusting to each new line
        } else {
            //std::cout << "Rendering character: " << *c << std::endl;
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }

    // Restore previous matrices and enable depth testing
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
}
