/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 * Project:     Glesly: my GLES-based rendering library
 * Purpose:     My test class for map rendering
 * Author:      György Kövesdi (kgy@teledigit.eu)
 * Licence:     GPL (see file 'COPYING' in the project root for more details)
 * Comments:    
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __SRC_EARTH_RENDER_H_INCLUDED__
#define __SRC_EARTH_RENDER_H_INCLUDED__

#include <primitive-render.h>
#include <cube-render.h>
#include <glesly/line-object.h>

/// Maximum number of elements for globe
/*! TODO */
#define ELEMS 9

namespace Ducktor
{
    class EarthRender: public Glesly::CubeRender
    {
     protected:
        EarthRender(Glesly::Render3D::RenderInfo & renderInfo);

        virtual void Initialize(void);
        virtual void Frame(const SYS::TimeDelay & frame_start_time);
        virtual void AfterFrame(void);

     public:
        virtual ~EarthRender();

        static inline Glesly::RenderPtr Create(Glesly::Render3D::RenderInfo & renderInfo)
        {
            SYS_DEBUG_STATIC(DM_GLESLY);
            return Glesly::RenderPtr(new EarthRender(renderInfo));
        }

     private:
        SYS_DEFINE_CLASS_NAME("Glesly::EarthRender");

    }; // class EarthRender

    class GlobeLines: public Glesly::LineObject<ELEMS>
    {
     protected:
        inline GlobeLines(Glesly::Render & render):
            Glesly::LineObject<ELEMS>(render)
        {
            Initialize();
        }

     public:
        inline static Glesly::ObjectPtr Create(Glesly::Render & render)
        {
            return (new GlobeLines(render))->ObjectBase::Create();
        }

     private:
        SYS_DEFINE_CLASS_NAME("Glesly::GlobeLines");

        void Initialize(void);

    }; // class GlobeLines

    class GlobeGridRender: public Glesly::PrimitiveRender
    {
     protected:
        GlobeGridRender(Glesly::Render3D::RenderInfo & renderInfo);

        virtual void Initialize(void);
        virtual void Frame(const SYS::TimeDelay & frame_start_time);

     public:
        virtual ~GlobeGridRender();

        static inline Glesly::RenderPtr Create(Glesly::Render3D::RenderInfo & renderInfo)
        {
            SYS_DEBUG_STATIC(DM_GLESLY);
            return Glesly::RenderPtr(new GlobeGridRender(renderInfo));
        }

     private:
        SYS_DEFINE_CLASS_NAME("Glesly::GlobeGridRender");

    }; // class GlobeGridRender

} // namespace Ducktor

#endif /* __SRC_EARTH_RENDER_H_INCLUDED__ */

/* * * * * * * * * * * * * End - of - File * * * * * * * * * * * * * * */
