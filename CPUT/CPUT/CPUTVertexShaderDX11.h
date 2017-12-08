/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _CPUTVERTEXSHADERDX11_H
#define _CPUTVERTEXSHADERDX11_H

#include "CPUT.h"
#include "CPUTShaderDX11.h"

class CPUTVertexShaderDX11 : public CPUTShaderDX11
{
protected:
    ID3D11VertexShader *mpVertexShader;

    // Destructor is not public.  Must release instead of delete.
    ~CPUTVertexShaderDX11(){ SAFE_RELEASE(mpVertexShader) }

public:
    static CPUTVertexShaderDX11 *CreateVertexShader(
        const cString     &name,
        const cString     &shaderMain,
        const cString     &shaderProfile,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );
    static CPUTVertexShaderDX11 *CreateVertexShaderFromMemory(
        const cString     &name,
        const cString     &shaderMain,
        const cString     &shaderProfile,
        const char        *pShaderSource,
        CPUT_SHADER_MACRO *pShaderMacros=NULL
    );

    CPUTVertexShaderDX11() : mpVertexShader(NULL), CPUTShaderDX11(NULL) {}
    CPUTVertexShaderDX11(ID3D11VertexShader *pD3D11VertexShader, ID3DBlob *pBlob) : mpVertexShader(pD3D11VertexShader), CPUTShaderDX11(pBlob) {}
    ID3D11VertexShader *GetNativeVertexShader() { return mpVertexShader; }
};

#endif //_CPUTVERTEXSHADER_H