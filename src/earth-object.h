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

#include <glesly/sphere.h>

#include <Debug/Debug.h>

namespace Ducktor
{
    static constexpr unsigned EarthResolution = 4;

    class EarthObject: public Glesly::Sphere<EarthResolution>
    {
        typedef Glesly::Sphere<EarthResolution> super;

     public:
        static constexpr float EarthRadius    =   2e7/M_PI;

     protected:
        EarthObject(Glesly::Render & render, int size):
            super(render, EarthRadius, size)
        {
            SYS_DEBUG_MEMBER(DM_GLESLY);
        }

     public:
        inline static Glesly::ObjectPtr Create(Glesly::Render & render, int size = 0)
        {
            return (new EarthObject(render, size))->ObjectBase::Create();
        }

        virtual ~EarthObject();

        void test(int mode);

     private:
        SYS_DEFINE_CLASS_NAME("Ducktor:EarthObject");

        void test(int i, int mode);

    }; // class Ducktor::EarthObject

} // namespace Ducktor

#endif /* __SRC_OBJECTS_GLESLY_EARTH_H_INCLUDED__ */

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
