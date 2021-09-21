#include "Mandlebrot.h"
#include <complex>
namespace myproj {
	int Mandlebrot::getIterations(double x, double y)
	{
		std::complex<double> c(x, y);
		std::complex<double> z = 0;
		int iterations = 0;

		while (iterations < MAX_ITERATIONS) {
			z = z * z + c;

			if (abs(z) > 2) {
				break;
			}

			iterations++;
		}

		return iterations;
	}
}
