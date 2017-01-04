//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2017 Stepan Prokofjev
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

//------------------------------------------------------------------
// Utility for calculating probabilities
// Implemented as script for simplify work with different "id" types
//------------------------------------------------------------------
const std::string LUNA_CHANCE_TABLE = \
"local ChanceTable = class() \
\
function ChanceTable:onInit(tbl) \
	local chances = {} \
\
	for k,v in pairs(tbl) do \
		if v > 0 then table.insert(chances, { chance = v, id = k }) end \
	end \
\
	table.sort(chances, function(v1, v2) return v1.chance < v2.chance end) \
\
	local sum = 0 \
	for _,v in ipairs(chances) do \
		v.chance = v.chance + sum \
		sum = v.chance \
	end \
\
	self.chances = chances \
end \
\
function ChanceTable:getNext() \
	local rand = math.random(0, 100) \
\
	for _,v in ipairs(self.chances) do \
		if rand <= v.chance then \
			return v.id \
		end \
	end \
end \
\
luna.utils = luna.utils or {} \
luna.utils.ChanceTable = ChanceTable";
