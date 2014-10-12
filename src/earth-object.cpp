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

void EarthBitmaps::test(int i)
{
 const PaCaLib::Target * target = static_cast<const PaCaLib::Target *>(textureTargets[i]);

 PaCaLib::DrawPtr dr = const_cast<PaCaLib::Target *>(target)->Draw();

 PaCaLib::PathPtr p = dr->NewPath();
 dr->SetColour(0.5, 0.2, 0.3, 0.6);
 dr->SetLineWidth(0.1);
 p->Move(-0.5, -0.5);
 p->Line(-0.5, 0.5);
 p->Line(0.5, 0.5);
 p->Line(0.5, -0.5);
 p->Close();
 p->Stroke();

 std::ostringstream os;

 os << "Próba:" << std::endl << i;

 dr->SetColour(1.0, 0.0, 0.5, 0.4);
 dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, os.str().c_str(), 0.12f, 1.0f);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
