#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

namespace myproj {
	class Bitmap
	{
	private:
		int _width{ 0 };
		int _height{ 0 };
		std::unique_ptr<uint8_t[]> _pPixels{ nullptr };
		int pixelAmount();

	public:
		Bitmap(int width, int height);
		void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
		bool write(std::string filename);
	};
}

#endif // !BITMAP_H_

