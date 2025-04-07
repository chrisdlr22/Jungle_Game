#ifndef _SCENE_
#define _SCENE_

#include<_common.h>

class _scene
{
    public:
        _scene();             //constructor
        virtual ~_scene();    //destructor
        bool shouldExit() {return requestExit;}

       GLint initGL();        //initialize game objects
       void reSize(GLint width,GLint Height); // resize window
       GLint drawScene();
       GLint pauseGame();
       GLvoid resizeScene(GLsizei, GLsizei);

       int winMsg(HWND	hWnd,			// Handle For This Window
                  UINT	uMsg,			// Message For This Window
                  WPARAM	wParam,			// Additional Message Information
                  LPARAM	lParam);

        float screenWidth, screenHeight; // for screen width and height;



    protected:

    private:
        bool requestExit = false;
};

#endif // _SCENE_
