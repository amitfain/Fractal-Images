#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include <fstream>

namespace myproj {
	Bitmap::Bitmap(int width, int height) : _width(width), _height(height), _pPixels(new uint8_t[width * height * 3]{}) {}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
		uint8_t* pPixel = _pPixels.get();
		pPixel += (y * 3) * _width + (x * 3);
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
	}

	bool Bitmap::write(std::string filename) {
		bool isWritten = true;
		myproj::BitmapFileHeader fileHeader;
		myproj::BitmapInfoHeader infoHeader;

		fileHeader.fileSize = sizeof(myproj::BitmapFileHeader) + sizeof(myproj::BitmapInfoHeader) + pixelAmount();
		fileHeader.dataOffset = sizeof(myproj::BitmapFileHeader) + sizeof(myproj::BitmapInfoHeader);

		infoHeader.height = _height;
		infoHeader.width = _width;

		std::ofstream ofs;
		ofs.open(filename, std::ios::out | std::ios::binary);

		if (!ofs) {
			isWritten = false;
		}
		else {
			ofs.write(reinterpret_cast<char*>(&fileHeader), sizeof(myproj::BitmapFileHeader));
			ofs.write(reinterpret_cast<char*>(&infoHeader), sizeof(myproj::BitmapInfoHeader));
			ofs.write(reinterpret_cast<char*>(_pPixels.get()), pixelAmount());

			if (!ofs) {
				isWritten = false;
			}
		}

		ofs.close();

		return isWritten;
	}

	int Bitmap::pixelAmount() {
		return _width * _height * 3;
	}
}
