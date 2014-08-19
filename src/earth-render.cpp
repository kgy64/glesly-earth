/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Project:     Glesly: my GLES-based rendering library
 * Purpose:     My test class for map rendering
 * Author:      György Kövesdi (kgy@teledigit.eu)
 * Licence:     GPL (see file 'COPYING' in the project root for more details)
 * Comments:    
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "earth-render.h"
#include <glesly-earth/earth-object.h>

using namespace Glesly;
using namespace Ducktor;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                                       *
 *     Class EarthRender:                                                                *
 *                                                                                       *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

EarthRender::EarthRender(Glesly::Render3D::RenderInfo & renderInfo):
    CubeRender(renderInfo)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

EarthRender::~EarthRender()
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

void EarthRender::Initialize(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 CameraSetNearPlane(1.0e5);
 CameraSetFarPlane(EarthObject::EarthRadius * 20.0);
 SceneMove(0.0f, 0.0f, EarthObject::EarthRadius);
 SceneRotate(-19.30926*(M_PI/180.0f), (47.46013-90.0)*(M_PI/180.0f));
}

void EarthRender::Frame(const SYS::TimeDelay & frame_start_time)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

void EarthRender::AfterFrame(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 glClear(GL_DEPTH_BUFFER_BIT);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                                       *
 *     Class GlobeGridRender:                                                            *
 *                                                                                       *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

GlobeGridRender::GlobeGridRender(Glesly::Render3D::RenderInfo & renderInfo):
    PrimitiveRender(renderInfo)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

GlobeGridRender::~GlobeGridRender()
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

void GlobeGridRender::Initialize(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 Glesly::ObjectList objs = GetObjectList();

 // TODO: Insert GlobeLines objects here
}

void GlobeGridRender::Frame(const SYS::TimeDelay & frame_start_time)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                                       *
 *     Class GlobeLines:                                                                 *
 *                                                                                       *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void GlobeLines::Initialize(void)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 GLushort elem_init[2*ELEMS];
 memset(elem_init, 0, sizeof(elem_init));

 // TODO: Initialize the position and colour

 elements.Bind(elem_init, myNoOfElements);

 SYS_DEBUG(DL_INFO1, "Number of elements: " << myNoOfElements << "/" << ELEMS);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
