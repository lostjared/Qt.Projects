#ifndef __LIB_H__
#define __LIB_H__
#include<QWidget>

#ifdef MAKE_LIB
#define LIB_EXPORT Q_DECL_EXPORT
#else 
#define LIB_EXPORT Q_DECL_IMPORT
#endif

extern "C" LIB_EXPORT void testFunc();

#endif
