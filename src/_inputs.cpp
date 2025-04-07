#include "_inputs.h"

_inputs::_inputs()
{
    //ctor
    isMsRotation = false;
    isMsTranslate = false;
}

_inputs::~_inputs()
{
    //dtor
}

void _inputs::keyPressed(_player* p1)
{
    switch(wParam)
    {
    case VK_LEFT:
    case 'A':
        p1->actionTrigger = p1->LEFTWALK;
        break;

    case VK_RIGHT:
    case 'D':
        p1->actionTrigger = p1->RIGHTWALK;
        break;

    case VK_UP:
    case 'W':
        p1->actionTrigger = p1->WALKUP;
        break;

    case VK_DOWN:
    case 'S':
        p1->actionTrigger = p1-> WALKDOWN;
        break;
    }
}

void _inputs::keyPressedPRLX(_parallax* PLRX)
{
     switch(wParam)
    {
    case VK_LEFT:
       PLRX->scroll(false,"left",PLRX->speed);
        break;

    case VK_RIGHT:
        PLRX->scroll(false,"right",PLRX->speed);
        break;

    case VK_UP:
        PLRX->scroll(false,"up",PLRX->speed);
        break;

    case VK_DOWN:
        PLRX->scroll(false,"down",PLRX->speed);
        break;
    }
}


/*void _inputs::keyPressed(_bullets &B)
{
    switch(wParam)
    {
    case VK_SPACE:
      B.actionTrigger= B.SHOOT;
    break;
    }
}
*/

void _inputs::keyUP(_player* p1)
{
    switch(wParam)
    {
        default:
            p1->actionTrigger = p1->STAND;
            break;
    }
}

void _inputs::mouseEventDown(_model* mdl, double x, double y)
{
    prev_msX = x;
    prev_msY = y;

        switch(wParam)
        {
        case MK_LBUTTON:
            isMsRotation = true;
            break;

        case MK_RBUTTON:
            isMsTranslate = true;
            break;
         case MK_MBUTTON: break;

         default: break;
        }
}

void _inputs::mouseEventUp()
{
   isMsRotation = false;
   isMsTranslate = false;
}

void _inputs::mouseMove(_model* mdl, double x, double y)
{
       if(isMsRotation){
            mdl->rotation.y += (x-prev_msX)/3.0;   //increase x alngle
            mdl->rotation.x += (y-prev_msY)/3.0;   //increase y angle
       }

       if(isMsTranslate){
            mdl->pos.x +=(x-prev_msX)/100.0;      //increase x position
            mdl->pos.y -=(y-prev_msY)/100.0;      //decrease y position
       }
       prev_msX =x;
       prev_msY =y;
}

void _inputs::mouseWheel(_model* mdl, double delta)
{
    mdl->pos.z +=delta/100;
}
