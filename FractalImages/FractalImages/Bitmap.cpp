#include "Bitmap.h"

namespace myproj {
	Bitmap::Bitmap(int width, int height) : _width(width), _height(height) {}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){}

	bool Bitmap::write(std::string filename) {
		return false;
	}
}
