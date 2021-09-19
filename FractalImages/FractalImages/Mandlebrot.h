#pragma once
namespace myproj {
	class Mandlebrot {
	public:
		static const int MAX_ITERATIONS = 100;

		static int getIterations(double x, double y);
	};
}

