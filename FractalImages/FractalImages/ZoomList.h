#pragma once
#include <memory>
#include <vector>
#include <utility>
#include "Zoom.h"

namespace myproj {
	class ZoomList
	{
		std::vector<Zoom> zooms;
		int _xCenter{ 0 };
		int _yCenter{ 0 };
		double _scale{ 1.0 };
		int _width{ 0 };
		int _height{ 0 };
	public:
		ZoomList(int width, int height) : zooms{}, _width(width), _height(height) {};
		void add(const Zoom &zoom);
		std::pair<double, double> doZoom(int x, int y);
	};
}

