#ifndef _PAUSEMENU_H
#define _PAUSEMENU_H

#include <_Common.h>
#include "_TextureLoader.h"

class _PauseMenu
{
    public:
        _PauseMenu();
        virtual ~_PauseMenu();

    void initPauseMenu(char* fileName);
    void drawPauseMenu(int windowWidth, int windowHeight);

    _TextureLoader* texture;

    protected:

    private:
};

#endif // _PAUSEMENU_H
