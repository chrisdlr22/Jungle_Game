#ifndef _BUTTON_H
#define _BUTTON_H
#include <_textureloader.h>
#include <_common.h>

class _button
{
    public:
        _button();
        virtual ~_button();

        _textureLoader *texture = new _textureLoader();

        void initButt(int,int,char* filename);
        void drawButt();

        vec3 buttPos;
        vec3 buttScl;

        vec3 vert[4];

        float xMax, xMin, yMax, yMin;
        int frameX, frameY;

    protected:

    private:
};

#endif // _BUTTON_H
