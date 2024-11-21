#ifndef _LANDINGPAGE_H
#define _LANDINGPAGE_H

#include <_Common.h>
#include <_TextureLoader.h>


class _LandingPage
{
    public:
        _LandingPage();
        virtual ~_LandingPage();

        void initLandingPage(char* fileName);
        void drawLandingPage(int windowWidth, int windowHeight);

        _TextureLoader* texture;

    protected:

    private:
};

#endif // _LANDINGPAGE_H
