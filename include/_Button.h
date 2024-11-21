#ifndef _BUTTON_H
#define _BUTTON_H

#include <_Common.h>
#include <string>
#include "_TextureLoader.h"

class _Button
{
    public:
        _Button(float x, float y, float width, float height, std::string label, char* textureFile);
        virtual ~_Button();

    void drawButton(); // draws the button
    bool isClicked(int mouseX, int mouseY); // checks if button is clicked

    float x;
    float y;
    float width;
    float height;
    std::string label; // button text label
    _TextureLoader* texture; // texture for button

    protected:

    private:
};

#endif // _BUTTON_H
