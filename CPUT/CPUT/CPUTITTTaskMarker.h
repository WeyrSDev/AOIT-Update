/////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2017 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __CPUTITTTASKMARKER_H__
#define __CPUTITTTASKMARKER_H__



#include "CPUT.h"

#ifdef CPUT_GPA_INSTRUMENTATION

// GPA ITT instrumentation helper class - only available in profile build
// Automatically open/close marks an ITT marker event for GPA
//-----------------------------------------------------------------------------
class CPUTITTTaskMarker
{
public:
    CPUTITTTaskMarker(__itt_domain *pITTDomain, __itt_string_handle *pITTStringHandle);
    ~CPUTITTTaskMarker();
private:
    __itt_domain *mpITTDomain;
    __itt_string_handle *mpITTStringHandle;
};

#endif
#endif // #ifndef __CPUTITTTASKMARKER_H__