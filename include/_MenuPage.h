#ifndef _MENUPAGE_H
#define _MENUPAGE_H

#include <_Common.h>
#include "_TextureLoader.h"
#include "_Button.h"
#include <vector>

class _MenuPage
{
    public:
        _MenuPage();
        virtual ~_MenuPage();

    void initMenuPage(char* fileName);
    void drawMenuPage(int windowWidth, int windowHeight);

    _TextureLoader* texture; // ptr texture for menu bckground
    _Button* buttons[3]; // buttons array

    void initButtons();

    protected:

    private:
};

#endif // _MENUPAGE_H
