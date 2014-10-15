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

void EarthObject::reset(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 DEBUG_OUT("EarthObject::reset() ...");
 EarthFiles files;
 for (int i = 0; i < 6; ++i) {
    *const_cast<Glesly::Target2D *>(textureTargets[i]) = *files.getTextures()[i];
    test(i);
 }

 ReinitGL();
 DEBUG_OUT("EarthObject::reset() ok");
}

void EarthBitmaps::test(int i)
{
 const PaCaLib::Target * target = static_cast<const PaCaLib::Target *>(textureTargets[i]);

 PaCaLib::DrawPtr dr = const_cast<PaCaLib::Target *>(target)->Draw();

 PaCaLib::PathPtr p = dr->NewPath();
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

 dr->SetLineWidth(0.02);
 dr->SetColour(0.2f, 0.3f, 0.3f, 0.5f);

 p->Bezier(-0.70f, -0.55f, +0.0f, -0.1f);
 p->Bezier(-0.55f, -0.70f, +0.1f, +0.0f);
 p->Bezier(+0.55f, -0.70f, +0.1f, +0.0f);
 p->Bezier(+0.70f, -0.55f, +0.0f, +0.1f);
 p->Bezier(+0.70f, +0.55f, +0.0f, +0.1f);
 p->Bezier(+0.55f, +0.70f, -0.1f, +0.0f);
 p->Bezier(-0.55f, +0.70f, -0.1f, +0.0f);
 p->Bezier(-0.70f, +0.55f, +0.0f, -0.1f);
 p->Close();
 p->Stroke();

 std::ostringstream os;

 os << "Próba:" << std::endl << i;

 dr->SetColour(1.0f, 0.0f, 0.5f, 0.4f);
 dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
