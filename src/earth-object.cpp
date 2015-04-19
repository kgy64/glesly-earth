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
            X = -(y-240.0f)/240.0f;
        break;
        case 2:
            A = (x-400.0f)/400.0f;
            B = (y-240.0f)/240.0f;
        break;
    }
 }

 return false;
}

void EarthObject::DrawWeb(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 PaCaLib::DrawPtr dr = Draw();
 dr->SetColourCompose(PaCaLib::COLOUR_COMPOSE_SUBTRACT);
 dr->SetColour(1, 1, 0, 1);
 dr->DrawText(0.0f, 1.0f, PaCaLib::CENTER, "N", 0.017);
 dr->SetColour(1, 0, 0, 1);
 dr->DrawText(0.0f, -1.0f, PaCaLib::CENTER, "S", 0.017);
 dr->SetLineWidth(0.001f);
 dr->SetColour(0, 0, 0, 0.35f);
 float x = 0.0f, y = 0.0f;
 // Longitude lines:
 for (x = -170.0f/180.0f; x < 185.0f/180.0f; x += 10.0f/180.0f) {
    PaCaLib::PathPtr pp = dr->NewPath();
    pp->Move(x, -85.0f/90.0f);
    for (y = -80.0f/90.0f; y < 81.0f/90.0f; y += 10.0f/90.0f) {
        pp->Line(x, y);
    }
    pp->Line(x, 85.0f/90.0f);
    pp->Draw();
    for (y = -75.0f/90.0f; y < 76.0f/90.0f; y += 25.0f/90.0f) {
        char txt[40];
        int ix = (int)(fabs(x*180.0f)+0.5f);
        if (ix == 0 || ix > 175) {
            sprintf(txt, "%d", ix);
        } else {
            sprintf(txt, x<0.0f ? "W %d" : "E %d", ix);
        }
        dr->DrawText(x-1.2f/180.0f, y+2.0f/90.0f, PaCaLib::CENTER, txt, 0.01f, 1.0f, -M_PI/2.0f);
    }
 }
 // Latitude lines:
 for (y = -80.0f/90.0f; y < 81.0f/90.0f; y += 10.0f/90.0f) {
    PaCaLib::PathPtr pp = dr->NewPath();
    pp->Move(-180.0f/180.0f, y);
    for (x = -170.0f/180.0f; x < 175.0f/180.0f; x += 10.0f/180.0f) {
        pp->Line(x, y);
    }
    pp->Close();
    pp->Draw();
    if ((y < -1.0f/90.0f || y > 1.0f/90.0f) && y < 75.0f/90.0f && y > -75.0f/90.0f) {
        for (x = -170.0f/180.0f; x < 181.0f/180.0f; x += 10.0f/180.0f) {
            char txt[40];
            sprintf(txt, y<0.0f ? "S %d" : "N %d", (int)(fabs(y*90.0f)+0.5f));
            dr->DrawText(x-5.0f/180.0f, y+0.7f/90.0f, PaCaLib::CENTER, txt, 0.01f);
        }
    }
 }
}

void EarthObject::LoadImage(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 static const char * const names[] = {
    CONFIG_ICON_DIR "/earth/earth+X.tga",
    CONFIG_ICON_DIR "/earth/earth-X.tga",
    CONFIG_ICON_DIR "/earth/earth+Y.tga",
    CONFIG_ICON_DIR "/earth/earth-Y.tga",
    CONFIG_ICON_DIR "/earth/earth+Z.tga",
    CONFIG_ICON_DIR "/earth/earth-Z.tga"
 };

 reset(names);
}

void EarthObject::test(int mode)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 switch (mode) {
    case 0:
        LoadImage();
    break;
    case 3:
    {
        PaCaLib::DrawPtr dr = Draw();
        dr->SetColour(0, 0, 0, 1);
        dr->DrawText(0.0f, 1.0f, PaCaLib::CENTER, "N", 0.017);
        dr->DrawText(0.0f, -1.0f, PaCaLib::CENTER, "S", 0.017);
        float x = 0.0f, y = 0.0f;
        for (x = -175.0f/180.0f; x < 181.0f/180.0f; x += 10.0f/180.0f) {
            for (y = -89.0f/90.0f; y < 90.0f/90.0f; y += 1.0f/90.0f) {
                char tmp[50];
                sprintf(tmp, "<%+04d/%+03d>", (int)(x*180.0f+0.5f), (int)(y*90.0f+0.5f));
                dr->DrawText(x, y, PaCaLib::CENTER, tmp, 0.012, 1.0f, 0*-M_PI/4);
            }
        }
    }
    break;
    case 4:
        DrawWeb();
    break;
    case 5:
        FillTest(Draw());
        // No break!
    case 1:
        // No break!
    case 2:
        for (int i = 0; i < 6; ++i) {
            test(i, mode);
        }
    break;
 }
}

void EarthObject::test(int i, int mode)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 const PaCaLib::Target * target = static_cast<const PaCaLib::Target *>(textureTargets[i]);

 PaCaLib::DrawPtr dr = const_cast<PaCaLib::Target *>(target)->Draw();

 switch (mode) {
    case 1:
    {
        PaCaLib::PathPtr p = dr->NewPath();

        dr->SetColour(0.5f, 0.2f, 0.3f, 0.6f);
        dr->SetColourCompose(PaCaLib::COLOUR_COMPOSE_SUBTRACT);
        dr->SetLineWidth(0.08);

        p->Move(-0.5f, -0.5f);
        p->Line(-0.5f, 0.5f);
        p->Line(0.5f, 0.5f);
        p->Line(0.5f, -0.5f);
        p->Close();
        p->Draw();
    }
    break;
    case 2:
    {
        PaCaLib::PathPtr p = dr->NewPath();

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
        p->Draw();

        p->Clear();
        p->Move( 0.0f, -1.0f);
        p->Line( 0.0f, +1.0f);
        p->Move(-1.0f,  0.0f);
        p->Line(+1.0f,  0.0f);
        p->Draw();

        std::ostringstream os;

        os << "Próba:" << std::endl << i;

        dr->SetColour(1.0f, 0.0f, 0.5f, 0.4f);
        dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f, M_PI/6.0f);
        dr->SetColour(0.0f, 1.0f, 0.5f, 0.4f);
        dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f, -M_PI/6.0f);
    }
    break;
    case 5:
        FillTest(dr);
    break;
 }
}

void EarthObject::FillTest(PaCaLib::DrawPtr dr)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 PaCaLib::PathPtr p = dr->NewPath();

 dr->SetColour(1.0f, 0.0f, 1.0f, 0.3f);
 dr->SetOutlineColour(0.0f, 1.0f, 0.0f, 0.4f);
 dr->SetColourCompose(PaCaLib::COLOUR_COMPOSE_ADD);
 dr->SetLineWidth(0.09f);
 dr->SetOutlineWidth(0.03f);

 for (float i  = 0.65f; i > -0.61f; i-=0.1f) {
    p->Line(+0.65f, i);
 }
 for (float i  = 0.65f; i > -0.61f; i-=0.1f) {
    p->Line(i, -0.65f);
 }
 for (float i  = -0.65f; i < 0.61f; i+=0.1f) {
    p->Line(-0.65f, i);
 }
 for (float i  = -0.65f; i < 0.61f; i+=0.1f) {
    p->Line(i, 0.65f);
 }
 p->Close();
 p->Draw(PaCaLib::Path::DRAW_STROKE_AND_FILL);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
