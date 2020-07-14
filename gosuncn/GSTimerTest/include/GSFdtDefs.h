/*
******************************************
Copyright (C): GOSUN
Filename : GSFDTEXPORT.H
Author :  zouyx
Description: ������������
********************************************
*/

#ifndef _GS_H_GSFDTEXPORT_H_
#define _GS_H_GSFDTEXPORT_H_


#include "GSTypes.h"
#include "GSDefs.h"


#ifdef _GSFOUNDATION_STATIC

# define GSFDT_CLASS  
# define GSFDT_API   

#else


#ifdef GSFOUNDATION_EXPORTS

# define GSFDT_CLASS  EXPORT_CLASS
# define GSFDT_API    EXPORT_API

#else

# define GSFDT_CLASS  IMPORT_CLASS
# define GSFDT_API    IMPORT_API

#endif

#endif



#ifdef _LINUX

#include <unistd.h>
#include <pthread.h>

#endif





#endif //end _GS_H_GSFDTEXPORT_H_
