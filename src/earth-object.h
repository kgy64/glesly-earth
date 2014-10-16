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

     public:
        const Glesly::Target2D * const * getTextures(void) const
        {
            return textureTargets;
        }

        EarthFiles(const char * const * names):
            textureFile_0(names[0]),
            textureFile_1(names[1]),
            textureFile_2(names[2]),
            textureFile_3(names[3]),
            textureFile_4(names[4]),
            textureFile_5(names[5]),
            textureTargets { &textureFile_0, &textureFile_1, &textureFile_2, &textureFile_3, &textureFile_4, &textureFile_5 }
        {
        }

        int getSize(void) const {
            int size = textureFile_0.GetWidth();
            for (int i = 0; i < 6; ++i) {
                ASSERT(textureTargets[i]->GetWidth() == size, "wrong width of pixmap file: " << textureTargets[i]->GetWidth() << " instead of " << size);
                ASSERT(textureTargets[i]->GetHeight() == size, "wrong height of pixmap file: " << textureTargets[i]->GetHeight() << " instead of " << size);
            }
            return size;
        }

    }; // class Ducktor::EarthFiles

    static constexpr Glesly::PixelFormat TARGET_FORMAT = Glesly::FORMAT_RGB_565;

    class EarthBitmaps
    {
     private:
        inline static PaCaLib::TargetPtr CreateTarget(int size)
        {
            return PaCaLib::Target::Create(size, size, TARGET_FORMAT);
        }

        PaCaLib::TargetPtr texture_0;
        PaCaLib::TargetPtr texture_1;
        PaCaLib::TargetPtr texture_2;
        PaCaLib::TargetPtr texture_3;
        PaCaLib::TargetPtr texture_4;
        PaCaLib::TargetPtr texture_5;

     protected:
        const Glesly::Target2D * textureTargets[6];

        inline EarthBitmaps(int size):
            textureTargets { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr }
        {
            if (size) {
                resize(size);
            }
        }

        inline void resize(int size)
        {
            texture_0 = CreateTarget(size);
            texture_1 = CreateTarget(size);
            texture_2 = CreateTarget(size);
            texture_3 = CreateTarget(size);
            texture_4 = CreateTarget(size);
            texture_5 = CreateTarget(size);
            textureTargets[0] = &*texture_0;
            textureTargets[1] = &*texture_1;
            textureTargets[2] = &*texture_2;
            textureTargets[3] = &*texture_3;
            textureTargets[4] = &*texture_4;
            textureTargets[5] = &*texture_5;
        }

        void test(int i, int mode);

    }; // class Ducktor::EarthBitmaps

    class EarthObject: public EarthBitmaps, public EarthParent
    {
     public:
        static constexpr float EarthRadius    =   2e7/M_PI;

     protected:
        EarthObject(Glesly::Render & render, int size = 0):
            EarthBitmaps(size),
            EarthParent(render, EarthObject::EarthRadius)
        {
            SYS_DEBUG_MEMBER(DM_GLESLY);
        }

     public:
        inline static Glesly::ObjectPtr Create(Glesly::Render & render)
        {
            return (new EarthObject(render))->ObjectBase::Create();
        }

        virtual ~EarthObject();

        void reset(int mode);

     private:
        SYS_DEFINE_CLASS_NAME("Ducktor:EarthObject");

        virtual const Glesly::Target2D * const * getTargets(void) const override
        {
            return textureTargets;
        }

    }; // class Ducktor::EarthObject

} // namespace Ducktor

#endif /* __SRC_OBJECTS_GLESLY_EARTH_H_INCLUDED__ */

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
