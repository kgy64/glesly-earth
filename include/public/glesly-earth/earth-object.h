/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Project:     Glesly Test: Test/Demo application for my GLES-based rendering library
 * Purpose:     
 * Author:      György Kövesdi (kgy@teledigit.eu)
 * Licence:     GPL (see file 'COPYING' in the project root for more details)
 * Comments:    
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __SRC_OBJECTS_GLESLY_EARTH_H_INCLUDED__
#define __SRC_OBJECTS_GLESLY_EARTH_H_INCLUDED__

#include <glesly/read-tga.h>
#include <Debug/Debug.h>

#include <glesly/surfaced-icosahedron.h>

namespace Ducktor
{
    static constexpr unsigned EarthResolution = 4;

    using EarthParent = Glesly::SurfacedIcosahedron<EarthResolution>;

    class EarthFiles
    {
     private:
        Glesly::ReadTGA textureFile_0;
        Glesly::ReadTGA textureFile_1;
        Glesly::ReadTGA textureFile_2;
        Glesly::ReadTGA textureFile_3;
        Glesly::ReadTGA textureFile_4;
        Glesly::ReadTGA textureFile_5;

     protected:
        const Glesly::Target2D * textureTargets[6];

        EarthFiles(void):
            textureFile_0(CONFIG_ICON_DIR "/earth/earth+X.tga", false),
            textureFile_1(CONFIG_ICON_DIR "/earth/earth-X.tga", false),
            textureFile_2(CONFIG_ICON_DIR "/earth/earth+Y.tga", false),
            textureFile_3(CONFIG_ICON_DIR "/earth/earth-Y.tga", false),
            textureFile_4(CONFIG_ICON_DIR "/earth/earth+Z.tga", false),
            textureFile_5(CONFIG_ICON_DIR "/earth/earth-Z.tga", false),
            textureTargets { &textureFile_0, &textureFile_1, &textureFile_2, &textureFile_3, &textureFile_4, &textureFile_5 }
        {
        }

    }; // class EarthFiles

    class EarthObject: public EarthFiles, public EarthParent
    {
     public:
        static constexpr float EarthRadius    =   2e7/M_PI;

     protected:
        EarthObject(Glesly::Render & render):
            EarthParent(render, EarthObject::EarthRadius, textureTargets)
        {
            SYS_DEBUG_MEMBER(DM_GLESLY);
        }

     public:
        inline static Glesly::ObjectPtr Create(Glesly::Render & render)
        {
            return (new EarthObject(render))->ObjectBase::Create();
        }

        virtual ~EarthObject()
        {
            SYS_DEBUG_MEMBER(DM_GLESLY);
        }

     private:
        SYS_DEFINE_CLASS_NAME("Ducktor:EarthObject");

    }; // class EarthObject

} // namespace Ducktor

#endif /* __SRC_OBJECTS_GLESLY_EARTH_H_INCLUDED__ */

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
