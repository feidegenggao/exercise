/*
 * ============================================================================
 *
 *       Filename:  lxf.h
 *
 *    Description:  namespace : lxf
 *
 *        Version:  1.0
 *        Created:  11/20/2012 11:52:26 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lxf (), 
 *        Company:  NDSL
 *
 * ============================================================================
 */
#ifndef     _LXF_LXF_HEADER_
#define     _LXF_LXF_HEADER_
#include    <iostream>
namespace lxf{
    namespace base{
        class widget{
            public:
                widget(){

                }
                ~widget(){

                }

                void printInfo(void) const;
        };
    };
};
#endif
