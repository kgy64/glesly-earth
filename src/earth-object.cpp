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

using namespace Ducktor;

void EarthBitmaps::test(PaCaLib::TargetPtr & target)
{
 PaCaLib::DrawPtr dr = target->Draw();

 dr->SetColour(0.0, 0.0, 1.0);
 dr->Paint();

 PaCaLib::PathPtr p = dr->NewPath();
 dr->SetColour(0.5, 1.0, 0.5);
 dr->SetLineWidth(0.1);
 p->Move(-0.5, -0.5);
 p->Line(-0.5, 0.5);
 p->Line(0.5, 0.5);
 p->Line(0.5, -0.5);
 p->Close();
 p->Stroke();

 dr->SetColour(1.0, 0.0, 0.0);
 dr->DrawText(0.0f, 0.0f, PaCaLib::CENTER, "Próba", 0.2f, 1.0f);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
