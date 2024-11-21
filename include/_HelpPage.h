#ifndef _HELPPAGE_H
#define _HELPPAGE_H

#include "_TextureLoader.h"
#include <_Common.h>

class _HelpPage
{
    public:
        _HelpPage();
        virtual ~_HelpPage();

    void initHelpPage(char* fileName);
    void drawHelpPage(int windowWidth, int windowHeight);

    _TextureLoader* texture;

    protected:

    private:
};

#endif // _HELPPAGE_H
