/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTSHADERDX11_H
#define _CPUTSHADERDX11_H

#include "CPUT.h"
#include <d3dcommon.h>
#include "CPUTRefCount.h"

class CPUTConfigBlock;

class CPUTShaderDX11 : public CPUTRefCount
{
protected:
    ID3DBlob          *mpBlob;

     // Destructor is not public.  Must release instead of delete.
    ~CPUTShaderDX11(){ SAFE_RELEASE(mpBlob); }

public:
    CPUTShaderDX11() : mpBlob(NULL) {}
    CPUTShaderDX11(ID3DBlob *pBlob) : mpBlob(pBlob) {}
    ID3DBlob *GetBlob() { return mpBlob; }

    bool ShaderRequiresPerModelPayload( CPUTConfigBlock &properties );
};

#endif //_CPUTPIXELSHADER_H