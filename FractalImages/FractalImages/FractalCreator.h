#pragma once
#include <string>
#include <memory>
#include "Zoom.h"
#include "Bitmap.h"
#include "ZoomList.h"

namespace myproj {
	class FractalCreator
	{
	private:
		int _width;
		int _height;
		Bitmap _bitmap;
		std::unique_ptr<int[]> _histogram;
		std::unique_ptr<int[]> _fractal;
		ZoomList _zoomList;
		int _total{ 0 };
	public:
		FractalCreator(int width, int height);
		void calculateIteration();
		void drawFractal();
		void addZoom(const Zoom &zoom);
		void writeBitmap(std::string fileName);
		void calculateTotalIterations();
	};
}

