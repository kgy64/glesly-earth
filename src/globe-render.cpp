/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Project:     Glesly: my GLES-based rendering library
 * Purpose:     My render class for globe rendering
 * Author:      György Kövesdi (kgy@teledigit.eu)
 * Licence:     GPL (see file 'COPYING' in the project root for more details)
 * Comments:    
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <glesly/shader-names.h>
#include <my-globe-vertex.h>
#include <my-globe-fragment.h>
#include <glesly/shader.h>

#include "globe-render.h"

using namespace Glesly;

GlobeRender::GlobeRender(Glesly::Render3D::RenderInfo & renderInfo, int width, int height):
    Render3D(renderInfo, width, height)
{
 SYS_DEBUG_MEMBER(DM_GLESLY);

 USE_VERTEX_SHADER(my_globe_vertex);
 USE_FRAGMENT_SHADER(my_globe_fragment);
}

GlobeRender::~GlobeRender()
{
 SYS_DEBUG_MEMBER(DM_GLESLY);
}

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
