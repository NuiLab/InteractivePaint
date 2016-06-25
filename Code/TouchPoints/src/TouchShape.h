#pragma once
#include "cinder/app/App.h"

using namespace cinder;

namespace touchpoints { namespace drawing
{
	struct TouchShape
	{
	public:
		float size() const;
		ColorA getColor() const;
		bool getFilledShape() const;
		float getSize() const;
		inline void DecrementFramesDrawn() { framesDrawn--; }
		inline bool ShouldDraw() { return framesDrawn > 0; }
		virtual void draw() = 0;
	protected:
		bool mFilledShapes;
		ColorA mColor;
		float mSize;
		//this is to help you manage how many framesDrawn to draw this object for. 
		int framesDrawn;
	};
}}