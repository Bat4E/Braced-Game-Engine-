#ifndef SCENE_H
#define SCENE_H

// Internal Libraries
#include <vector>

// Custom Libraries
#include "_Scene.h"
#include "_LightSetup.h"
#include "_Models.h"
#include "_KbMs.h"
#include "_TerrainGenerator.h"
#include "_Common.h"
#include "_Camera.h"

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
        GLvoid initFog();

        GLvoid mouseMapping(int, int);
        GLvoid updateObjectRotation(vec3* target);

        GLvoid t_switch();

        GLvoid insertObject(char* tex_file, char* mdl_file); // Custom Models
        GLvoid insertObject(int);                           // Premade

        GLvoid insertLight();

        // Game Engine Variables
        GLdouble mouseX, mouseY, mouseZ;
        float screenWidth, screenHeight;

        enum mode{ TRANSFORM, ROTATE, SCALE };   // Used to switch between what edit will happen to object
        mode transform_trigger;

        bool state_change;
        bool editmode;

    protected:

    private:
};

#endif // SCENE_H
