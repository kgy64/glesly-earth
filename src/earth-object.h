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
#include <pacalib/pacalib.h>
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
            textureFile_0(CONFIG_ICON_DIR "/earth/earth+X.tga"),
            textureFile_1(CONFIG_ICON_DIR "/earth/earth-X.tga"),
            textureFile_2(CONFIG_ICON_DIR "/earth/earth+Y.tga"),
            textureFile_3(CONFIG_ICON_DIR "/earth/earth-Y.tga"),
            textureFile_4(CONFIG_ICON_DIR "/earth/earth+Z.tga"),
            textureFile_5(CONFIG_ICON_DIR "/earth/earth-Z.tga"),
            textureTargets { &textureFile_0, &textureFile_1, &textureFile_2, &textureFile_3, &textureFile_4, &textureFile_5 }
        {
        }

    }; // class Ducktor::EarthFiles

    class EarthBitmaps
    {
     private:
        PaCaLib::TargetPtr texture_0;
        PaCaLib::TargetPtr texture_1;
        PaCaLib::TargetPtr texture_2;
        PaCaLib::TargetPtr texture_3;
        PaCaLib::TargetPtr texture_4;
        PaCaLib::TargetPtr texture_5;

     protected:
        const Glesly::Target2D * textureTargets[6];

        EarthBitmaps(void):
            texture_0(PaCaLib::Target::Create(2048, 2048)),
            texture_1(PaCaLib::Target::Create(2048, 2048)),
            texture_2(PaCaLib::Target::Create(2048, 2048)),
            texture_3(PaCaLib::Target::Create(2048, 2048)),
            texture_4(PaCaLib::Target::Create(2048, 2048)),
            texture_5(PaCaLib::Target::Create(2048, 2048)),
            textureTargets { &*texture_0, &*texture_1, &*texture_2, &*texture_3, &*texture_4, &*texture_5 }
        {
            test(texture_0);
            test(texture_1);
            test(texture_2);
            test(texture_3);
            test(texture_4);
            test(texture_5);
        }

        void test(PaCaLib::TargetPtr & target);

    }; // class Ducktor::EarthBitmaps

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
