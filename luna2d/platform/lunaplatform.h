//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014 Stepan Prokofjev
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

// Supported platforms
#define LUNA_PLATFORM_UNKNOWN 0
#define LUNA_PLATFORM_QT 1
#define LUNA_PLATFORM_ANDROID 2
#define LUNA_PLATFORM_IOS 3

// Desktop emulator based on Qt
#if defined(QT_CORE_LIB)
	#define LUNA_PLATFORM LUNA_PLATFORM_QT

// Android
#elif defined(__ANDROID__)
	#define LUNA_PLATFORM LUNA_PLATFORM_ANDROID

	#include <string>
	#include <cstdlib>

	// Android's GCC don't support std::stoi
	namespace std
	{
		inline int stoi(const string& str)
		{
			return atoi(str.c_str());
		}
	}


// iOS
#elif defined(__APPLE__)
	#define LUNA_PLATFORM LUNA_PLATFORM_IOS

// Check for unsupported platforms
#else
	#define LUNA_PLATFORM LUNA_PLATFORM_UNKNOWN
	#error "Unsupported platform"
#endif
