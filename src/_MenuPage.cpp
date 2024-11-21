#include "_MenuPage.h"

_MenuPage::_MenuPage()
{
    //ctor
    texture = new _TextureLoader();
    for (int i = 0; i < 3; ++i) {
        buttons[i] = nullptr; // init pointer to nullptr
    }
}

_MenuPage::~_MenuPage()
{
    //dtor
    delete texture;
    for (int i = 0; i < 3; ++i) {
        delete buttons[i]; // free alloc memory for buttons
    }
}

void _MenuPage::initMenuPage(char* fileName)
{
    // load menu bckground img or init menu component here
    texture->loadTexture(fileName);
    initButtons();
}

void _MenuPage::initButtons()
{
    std::cout << "Initializing buttons..." << std::endl;

    buttons[0] = new _Button(-0.5f, 0.2f, 0.5f, 0.1f, "New Game", (char*)"images/teapot.jpg"); // newgame.jpg
    std::cout << "Button 1 initialized." << std::endl;

    buttons[1] = new _Button(-0.5f, 0.0f, 0.5f, 0.1f, "Help", (char*)"images/teapot.jpg"); // help.jpg
    std::cout << "Button 2 initialized." << std::endl;

    buttons[2] = new _Button(-0.5f, -0.2f, 0.5f, 0.1f, "Exit", (char*)"images/tex.jpg"); // exit.jpg
    std::cout << "Button 3 initialized." << std::endl;
}

void _MenuPage::drawMenuPage(int windowWidth, int windowHeight)
{
    //std::cout << "Drawing MenuPage" << std::endl;
    //std::cout << "Window Width: " << windowWidth << ", Window Height: " << windowHeight << std::endl;
    //std::cout << "Image Width: " << texture->width << ", Image Height: " << texture->height << std::endl;

    // Calculate the aspect ratios of the window and the image
    float windowAspectRatio = (float)windowWidth / windowHeight;
    float imageAspectRatio = (float) texture->width / texture->height;

    // scaling factors
    float scaleX = 1.0; // 1.5
    float scaleY = 1.0; // 1.0
    float zValue = -1.0; // -1.5

    // Adjust scaling factors based on aspect ratios
    if (windowAspectRatio > imageAspectRatio)
    {
        // window is wider than image, scale down height
        scaleX = (float)imageAspectRatio / windowAspectRatio;
    }
    else
    {
        // window is taller than the image, scale down width
        scaleY = (float)windowAspectRatio / imageAspectRatio;
    }

    // Debugging values to verify correct calculations
    //std::cout << "After if stmt: Window Width: " << windowWidth << ", Window Height: " << windowHeight << std::endl;
    //std::cout << "After if stmt: Image Width: " << texture->width << ", Image Height: " << texture->height << std::endl;
    //std::cout << "After if stmt: Scale X: " << scaleX << ", Scale Y: " << scaleY << std::endl;

    // Set color for rendering (white to preserve texture color
    glColor3f(1.0, 1.0, 1.0); // any geometry shape after this will bind to it

    // draw the menu, include options like Start Game, Help, and Exit

    // bind texture to draw a quad for bckground
    texture->bindTexture();

    // disable light to ensure texture color is not affected
    glDisable(GL_LIGHTING);

    // Draw a quad (rectangle) with the texture mapped onto it
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

    // draw button
    for (int i = 0; i < 3; ++i) {
        if (buttons[i]) {
            buttons[i]->drawButton();
        }
    }

    //std::cout << "MenuPage Quad drawn successfully." << std::endl;

    // re-enable lighting
    glEnable(GL_LIGHTING);
}
