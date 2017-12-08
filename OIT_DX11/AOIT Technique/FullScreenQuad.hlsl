/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

// Vertex shader
struct VS_OUTPUT 
{
	float4 pos : SV_POSITION;
	float2 tex : TEX_COORD0;
};

VS_OUTPUT VSMain(float4 Input : SV_POSITION)
{
	VS_OUTPUT output;
	output.pos = Input;
	output.tex = (Input.xy * float2(1, -1) + 1.0f)/2.0f;
	return output;
}