#include "_scene.h"
#include "_lightsetting.h"
#include "_textureloader.h"
#include "_inputs.h"
#include "_model.h"
#include "_parallax.h"
#include "_player.h"
#include "_menu.h"
#include "_object.h"
#include "_timer.h"

_inputs *KbMs = new _inputs();
_parallax *landingPage = new _parallax();
_parallax *mainMenu = new _parallax();
_parallax *helpMenu = new _parallax();
_parallax *tutMap = new _parallax();
_parallax *pauseMenu = new _parallax();
_object *startButton =  new _object();
_object *exitButton = new _object();
_object *helpButton = new _object();
//_object *titleBanner = new _object();
_menu *menuState = new _menu();
_player *player = new _player();
bool isPaused = false;



_scene::_scene()
{
    //ctor
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

_scene::~_scene()
{
    //dtor
}
GLint _scene::initGL()
{
   glShadeModel(GL_SMOOTH);
   glClearColor(0.0f,0.0f,0.0f,0.0f);
   glClearDepth(2.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);

   glEnable(GL_BLEND); // take off the transparent background
   glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

  // glEnable(GL_COLOR_MATERIAL);
  // myLight->setLight(GL_LIGHT0);

  landingPage->initPrlx("images/landingpage.png"); //load landing image
  mainMenu->initPrlx("images/menu_pg.png"); // load prlx main menu
  helpMenu->initPrlx("images/helpmenu.png"); //load prlx help menu
  tutMap->initPrlx("images/gameplay.png"); //load prlx tutorial map
  pauseMenu->initPrlx("images/pausemenu.png"); //load pause menu
  //player->initPlayer(6,10, "images/monkeysprite.png"); //load player texture, removed for now
  player->actionTrigger = player->STAND; //Player waits for user input

   return true;
}

void _scene::reSize(GLint width, GLint height)
{
    GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
    // keep track of the resize window
    glViewport(0,0,width,height); // adjusting the viewport
    glMatrixMode(GL_PROJECTION);  // perspective projection settings
    glLoadIdentity();             // identity matrix
    gluPerspective(45,aspectRatio,0.1,100.0); // projection settings
    glMatrixMode(GL_MODELVIEW);   // camera and model settings
    glLoadIdentity();             // identity matrix

    // dim.x = GetSystemMetrics(SM_CXSCREEN);
    // dim.y = GetSystemMetrics(SM_CYSCREEN);
}

GLint _scene::drawScene()
{
    if(isPaused)
    {
        pauseGame();
        return true;
    }
    else
    {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    }
    switch (menuState->gPage)
    {
case Page_Landing:

    glPushMatrix();
    glScalef(12.5,12.5,1.0);
    glDisable(GL_LIGHTING);
    landingPage->drawBackground(screenWidth, screenHeight);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    break;

case Page_MainMenu:

    glDisable(GL_DEPTH_TEST);

    glPushMatrix();
    glScalef(12.5,12.5,1.0);
    glDisable(GL_LIGHTING);
    mainMenu->drawBackground(screenWidth, screenHeight);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    break;

case Page_Game:
    glPushMatrix();
    glScalef(12.5,12.5,1.0);
    glDisable(GL_LIGHTING);
    tutMap->drawBackground(screenWidth, screenHeight);
    glEnable(GL_LIGHTING);
    glPopMatrix();

//player
    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glDisable(GL_LIGHTING);
    player->drawPlayer();
    player->playerActions();
    glEnable(GL_LIGHTING);
    glPopMatrix();

    break;

case Page_Help:

    glPushMatrix();
    glScalef(12.5,12.5,1.0);
    glDisable(GL_LIGHTING);
    helpMenu->drawBackground(screenWidth, screenHeight);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    break;
    }

return true;

}




int _scene::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_KEYDOWN: //for player keys later
        switch(wParam)
        {
            case VK_RETURN: //Enter key
                {
                    if(menuState->gPage == Page_Landing)
                    {
                        menuState->gPage = Page_MainMenu;
                    }
                else if(isPaused == true)
                {
                    requestExit = true;
                }
                break;
                }
            case VK_ESCAPE: //Esc key
                {
                    if(menuState->gPage == Page_Help)
                    {
                        menuState->gPage = Page_MainMenu;
                    }
                    else if (menuState->gPage == Page_MainMenu)
                    {
                            requestExit = true;
                    }
                    break;
                }
            case 'N': //input N
                {
                    if(menuState->gPage == Page_MainMenu)
                    {
                        menuState->gPage = Page_Game;
                    }
                    break;
                }
            case 'H': //input H
                {
                    if(menuState->gPage == Page_MainMenu)
                    {
                        menuState->gPage = Page_Help;
                    }
                    break;
                }
            case 'L': //input L
                {
                    if(menuState->gPage == Page_MainMenu)
                    {
                        menuState->gPage = Page_Landing;
                    }
                    break;
                }
            }
             break;


    case WM_KEYUP:
        switch(wParam)
        {
        case VK_ESCAPE:
            if(menuState->gPage == Page_Game)
            {
                if(isPaused == false)
                {
                    isPaused = true;
                }
                else if(isPaused == true)
                {
                    isPaused = false;
                }
            }
            break;
        }
        break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:

        break;
    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:

        break;
    case WM_MOUSEMOVE:

        break;
    case WM_MOUSEWHEEL:

        break;
    }
}

GLint _scene::pauseGame()
{
        glPushMatrix();      //Loading background w/ Parallax
        glScalef(12.5,12.5,1.0);
        glDisable(GL_LIGHTING);
        pauseMenu->drawBackground(screenWidth, screenHeight);
        glEnable(GL_LIGHTING);
     glPopMatrix();
}
