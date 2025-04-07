#include "_button.h"

_button::_button()
{
    //ctor
    vert[0].x =-0.5; vert[0].y = -0.5; vert[0].z =-1.0;
    vert[1].x = 0.5; vert[1].y = -0.5; vert[1].z =-1.0;
    vert[2].x = 0.5; vert[2].y =  0.5; vert[2].z =-1.0;
    vert[3].x =-0.5; vert[3].y =  0.5; vert[3].z =-1.0;
}

_button::~_button()
{
    //dtor
}
void _button::initButt(int x, int y, char* filename)
{
    buttPos.x = 0.0;
    buttPos.y = -0.2;
    buttPos.z = -1.0;

    buttScl.x = 0.25;
    buttScl.y = 0.25;
    buttScl.z = 1.0;

    frameX = x;
    frameY = y;

    texture->loadTexture(filename);

    xMin = 0;
    yMax = 2.0/(float)frameY;
    xMax = 1.0/(float)frameX;
    yMin = yMax-1.0/(float)frameY;
}

void _button::drawButt()
{
    glTranslatef(buttPos.x, buttPos.y, buttPos.z);
    glScalef(buttScl.x, buttScl.y, buttScl.z);

    glColor3f(1.0,1.0,1.0);
    texture->textureBinder();


    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);

        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);

        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);

        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);

    glEnd();
}
