#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <_Common.h>

#include "_Scene.h"
#include "_LightSetup.h"
#include "_Models.h"
#include "_KbMs.h"

class Scene
{
    public:
        Scene();
        virtual ~Scene();

        GLint initGL();
        GLint drawScene();
        GLvoid resizeScene(GLsizei, GLsizei);

        int winMsg(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

        // Game Engine Functions
        GLvoid insertObject(int);
        GLvoid insertLight();

    protected:

    private:
};

#endif // SCENE_H