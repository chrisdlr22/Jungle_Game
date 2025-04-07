#ifndef _OBJECT_H
#define _OBJECT_H
#include <_textureloader.h>
#include <_common.h>

class _object
{
    public:
        _object();
        virtual ~_object();

        _textureLoader *texture = new _textureLoader();

        void initObj(int,int,char* filename);
        void drawObj();

        vec3 objPos;
        vec3 objScl;

        vec3 vert[4];

        float xMax, xMin, yMax, yMin;
        int frameX, frameY;

    protected:

    private:
};

#endif // _OBJECT_H
