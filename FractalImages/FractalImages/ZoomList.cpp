#include "ZoomList.h"

namespace myproj {
	void ZoomList::add(const Zoom &zoom) {
		zooms.push_back(zoom);
		_xCenter += (zoom._x - _width / 2) * _scale;
		_yCenter += (zoom._y - _height / 2) * _scale;
		_scale *= zoom._scale;
	}

	std::pair<double, double> ZoomList::doZoom(int x, int y) {
		double xRel = (x - _width / 2.0) *_scale + _xCenter;
		double yRel = (y - _height / 2.0) * _scale + _yCenter;

		return std::pair<double, double>(xRel, yRel);
	}
}
