/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTTEXTURE_H
#define _CPUTTEXTURE_H

#include "CPUT.h"
#include "CPUTRefCount.h"

class CPUTTexture : public CPUTRefCount
{
protected:
    cString       mName;
    eCPUTMapType  mMappedType;

    ~CPUTTexture(){} // Destructor is not public.  Must release instead of delete.

public:
    CPUTTexture()              : mMappedType(CPUT_MAP_UNDEFINED) {}
	CPUTTexture(cString &name) : mMappedType(CPUT_MAP_UNDEFINED), mName(name) {}
    static CPUTTexture *CreateTexture( const cString &name, const cString absolutePathAndFilename, bool loadAsSRGB );
	// ##### what is the OpenGL equivalent of mapping a texture? Really all we are returning here is a void* to memory and row pitch and depth.
	// no reason to be DX specific.
#ifdef CPUT_FOR_DX11
    virtual D3D11_MAPPED_SUBRESOURCE  MapTexture(   CPUTRenderParameters &params, eCPUTMapType type, bool wait = true ) = 0;
#elif defined(CPUT_FOR_OGL)
    virtual void *MapTexture(   CPUTRenderParameters &params, eCPUTMapType type, bool wait = true ) = 0;
#endif
    virtual void                      UnmapTexture( CPUTRenderParameters &params )                                      = 0; // TODO: Store params on Map() and don't require here.
	const cString &GetName() { return mName; }

};

#endif //_CPUTTEXTURE_H