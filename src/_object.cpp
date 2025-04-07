#include "_object.h"
#
_object::_object()
{
    //ctor
    vert[0].x =-0.5; vert[0].y = -0.5; vert[0].z =-1.0;
    vert[1].x = 0.5; vert[1].y = -0.5; vert[1].z =-1.0;
    vert[2].x = 0.5; vert[2].y =  0.5; vert[2].z =-1.0;
    vert[3].x =-0.5; vert[3].y =  0.5; vert[3].z =-1.0;
}

_object::~_object()
{
    //dtor
}
void _object::initObj(int x, int y, char* filename)
{
    objPos.x = 0.0;
    objPos.y = -0.2;
    objPos.z = -1.0;

    objScl.x = 0.25;
    objScl.y = 0.25;
    objScl.z = 1.0;

    frameX = x;
    frameY = y;

    texture->loadTexture(filename);

    xMin = 0;
    yMax = 2.0/(float)frameY;
    xMax = 1.0/(float)frameX;
    yMin = yMax-1.0/(float)frameY;
}

void _object::drawObj()
{
    glTranslatef(objPos.x, objPos.y, objPos.z);
    glScalef(objScl.x, objScl.y, objScl.z);

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
