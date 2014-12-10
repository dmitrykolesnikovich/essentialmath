//===============================================================================
// @ IvIndexBufferOGL.h
// 
// Description
// ------------------------------------------------------------------------------
// Copyright (C) 2008   Elsevier, Inc.
//
// Change history:
//
// Usage notes
//===============================================================================

#ifndef __IvIndexBufferOGL__h__
#define __IvIndexBufferOGL__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include "../IvIndexBuffer.h"
#include "IvResourceManager.h"
#ifdef PLATFORM_OSX
#include <OpenGL/gl3.h>
#else
#include <GL/glew.h>
#include <GL/gl3.h>
#endif

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvIndexBufferOGL : private IvIndexBuffer
{
public:
    // interface routines
    virtual void* BeginLoadData();
    virtual bool  EndLoadData();
    
    friend class IvResourceManagerOGL;
    friend class IvRendererOGL;
    
private:
    // constructor/destructor
    IvIndexBufferOGL(); 
	~IvIndexBufferOGL();

    // creation 
    bool Create( unsigned int numVertices, void* data, IvDataUsage usage );
    
    // destruction
    void Destroy();
    
    // activate
    bool MakeActive();
    
private:
    // copy operations
    IvIndexBufferOGL(const IvIndexBufferOGL& other);
	IvIndexBufferOGL& operator=(const IvIndexBufferOGL& other);

	GLuint      mBufferID;
    IvDataUsage mUsage;
};


//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------

#endif
