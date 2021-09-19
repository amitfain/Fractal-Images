#include "Mandlebrot.h"
#include <complex>
namespace myproj {
	int Mandlebrot::getIterations(double x, double y)
	{
		std::complex<double> c(x, y);
		std::complex<double> z{};

		for (int i = 0; i < MAX_ITERATIONS && abs(z) <= 2; i++) {
			z = z * z + c;
		}

		if (abs(z) > 2) {
			return 255;
		}

		return 0;
	}
}
