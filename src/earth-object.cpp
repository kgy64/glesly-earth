/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Project:     
 * Purpose:     
 * Author:      
 * License:     GPL (see file 'COPYING' in the project root for more details)
 * Comments:    
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "earth-object.h"

#include <sstream>

static const char * const names[] = {
    CONFIG_ICON_DIR "/earth/earth+X.tga",
    CONFIG_ICON_DIR "/earth/earth-X.tga",
    CONFIG_ICON_DIR "/earth/earth+Y.tga",
    CONFIG_ICON_DIR "/earth/earth-Y.tga",
    CONFIG_ICON_DIR "/earth/earth+Z.tga",
    CONFIG_ICON_DIR "/earth/earth-Z.tga"
};

using namespace Ducktor;

EarthObject::~EarthObject()
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 DEBUG_OUT("EarthObject: deleted");
}

extern float X,Y,A,B;

bool EarthObject::MouseClick(float x, float y, int index, int count)
{
 DEBUG_OUT("MouseClick(" << x << ", " << y << ", " << index << ", " << count << ")");

 if (count == 0) {
    switch (index) {
        case 0:
            Y = (x-400.0f)/400.0f;
            X = (y-240.0f)/240.0f;
        break;
        case 2:
            A = (x-400.0f)/400.0f;
            B = (y-240.0f)/240.0f;
        break;
    }
 }

 return false;
}

void EarthObject::test(int mode)
{
 switch (mode) {
    case 0:
        reset(names);
    break;
    case 3:
    {
        PaCaLib::DrawPtr dr = Draw();
        dr->SetColour(0, 0, 0, 1);
        dr->DrawText(0.0f, M_PI/2.0f, PaCaLib::CENTER, "N", 0.017);
        dr->DrawText(0.0f, -M_PI/2.0f, PaCaLib::CENTER, "S", 0.017);
        float x = 0.0f, y = 0.0f;
        for (x = -175.0f; x < 181.0f; x += 10.0f) {
            for (y = -89.0f; y < 90.0f; y += 1.0f) {
                char tmp[50];
                sprintf(tmp, "<%+04d/%+03d>", (int)x, (int)y);
                float longitude = x * M_PI/180.0f;
                float latitude = y * M_PI/180.0f;
                dr->DrawText(longitude, latitude, PaCaLib::CENTER, tmp, 0.01);
            }
        }
    }
    break;
    case 1: // no break!
    case 2:
        for (int i = 0; i < 6; ++i) {
            test(i, mode);
        }
    break;
 }

 ReinitGL();
}

void EarthObject::test(int i, int mode)
{
 const PaCaLib::Target * target = static_cast<const PaCaLib::Target *>(textureTargets[i]);

 PaCaLib::DrawPtr dr = const_cast<PaCaLib::Target *>(target)->Draw();
 PaCaLib::PathPtr p = dr->NewPath();

 switch (mode) {
    case 1:
    {
        dr->SetColour(0.5f, 0.2f, 0.3f, 0.6f);
        dr->SetColourCompose(PaCaLib::COLOUR_COMPOSE_SUBTRACT);
        dr->SetLineWidth(0.08);

        p->Move(-0.5f, -0.5f);
        p->Line(-0.5f, 0.5f);
        p->Line(0.5f, 0.5f);
        p->Line(0.5f, -0.5f);
        p->Close();
        p->Stroke();
        p->Clear();
    }
    break;
    case 2:
    {
        dr->SetColour(0.2f, 0.3f, 0.3f, 0.5f);
        dr->SetColourCompose(PaCaLib::COLOUR_COMPOSE_SUBTRACT);
        dr->SetLineWidth(0.02);

        static constexpr float p1 = 0.95f;
        static constexpr float p2 = 0.80f;

        p->Bezier(-p1, -p2, +0.0f, -0.1f);
        p->Bezier(-p2, -p1, +0.1f, +0.0f);
        p->Bezier(+p2, -p1, +0.1f, +0.0f);
        p->Bezier(+p1, -p2, +0.0f, +0.1f);
        p->Bezier(+p1, +p2, +0.0f, +0.1f);
        p->Bezier(+p2, +p1, -0.1f, +0.0f);
        p->Bezier(-p2, +p1, -0.1f, +0.0f);
        p->Bezier(-p1, +p2, +0.0f, -0.1f);
        p->Close();
        p->Stroke();

        p->Clear();
        p->Move( 0.0f, -1.0f);
        p->Line( 0.0f, +1.0f);
        p->Move(-1.0f,  0.0f);
        p->Line(+1.0f,  0.0f);
        p->Stroke();

        std::ostringstream os;

        os << "Próba:" << std::endl << i;

        dr->SetColour(1.0f, 0.0f, 0.5f, 0.4f);
        dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f, M_PI/6.0f);
        dr->SetColour(0.0f, 1.0f, 0.5f, 0.4f);
        dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f, -M_PI/6.0f);
    }
    break;
 }
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
