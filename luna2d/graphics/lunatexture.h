//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2015 Stepan Prokofjev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#pragma once

#include "lunagl.h"
#include "lunaglhelpers.h"
#include "lunaimage.h"
#include "lunalua.h"
#include "lunaassets.h"

namespace luna2d{

class LUNATexture : public LUNAAsset
{
public:
	LUNATexture(const LUNAImage& image);
	~LUNATexture();

private:
	int width, height;
	LUNAColorType colorType;
	GLuint id;

private:
	void CreateGlTexture(const std::vector<unsigned char>& data);

public:
	int GetWidth();
	int GetHeight();
	GLuint GetId();
	bool IsValid(); // Check for texture is valid. Can be invalid after loss GL context
	void Bind();
	void Unbind();
	virtual void Reload(); // Reload texture if OpenGL context was lost
};

}
