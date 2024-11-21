#include "_PauseMenu.h"

_PauseMenu::_PauseMenu()
{
    //ctor
    texture = new _TextureLoader();
}

_PauseMenu::~_PauseMenu()
{
    //dtor
    delete texture;
}

void _PauseMenu::initPauseMenu(char* fileName)
{
    texture->loadTexture(fileName);
}

void _PauseMenu::drawPauseMenu(int windowWidth, int windowHeight)
{
    float windowAspectRatio = (float)windowWidth / windowHeight;
    float imageAspectRatio = (float)texture->width / texture->height;

    float scaleX = 1.0f;
    float scaleY = 0.8f;
    float zValue = -2.0f;

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

    // Draw text on top of the texture
    glColor3f(0.0f, 0.0f, 0.0f);
    const char* pauseText = "Game Pause\nPress Enter to Quit\nPress Escape to Resume";
    float lineSpacing = 0.1f;
    float xPos = -0.3f;
    float yPos = 0.2f;
    float zPos = -1.0f;

    glRasterPos3f(xPos, yPos, zPos);

    for (const char* c = pauseText; *c != '\0'; c++) {
        if (*c == '\n') {
            yPos -= lineSpacing;
            glRasterPos3f(xPos, yPos, zPos); // adjust raster position for new line
        } else {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
        }
    }
    glEnable(GL_LIGHTING);
}
