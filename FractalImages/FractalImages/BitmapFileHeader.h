#pragma pack(2)
#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

namespace myproj {

	struct BitmapFileHeader {
		char header[2]{ 'B', 'M' };
		int32_t fileSize;
		int32_t reserved{ 0 };
		int_fast32_t dataOffset;
	};

}

#endif // !BITMAPFILEHEADER_H_
