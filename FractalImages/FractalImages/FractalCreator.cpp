#include "FractalCreator.h"
#include "Mandlebrot.h"
#include "Zoom.h"

namespace myproj {
    FractalCreator::FractalCreator(int width, int height) :
        _width(width),
        _height(height),
        _bitmap(width, height),
        _histogram(new int[Mandlebrot::MAX_ITERATIONS]{}),
        _fractal(new int[width * height]{}),
        _zoomList(width, height) {
        _zoomList.add(Zoom(width / 2, height / 2, 4.0 / width));
    }

	void FractalCreator::calculateIteration() {
        for (int x = 0; x < _width; x++) {
            for (int y = 0; y < _height; y++) {
                std::pair<double, double> fractle = _zoomList.doZoom(x, y);

                int iteration = myproj::Mandlebrot::getIterations(fractle.first, fractle.second);
                _fractal[y * _width + x] = iteration;

                if (iteration != myproj::Mandlebrot::MAX_ITERATIONS) {
                    _histogram[iteration]++;
                }
            }
        }
	}

    void FractalCreator::drawFractal() {
        for (int x = 0; x < _width; x++) {
            for (int y = 0; y < _height; y++) {
                int iterations = (_fractal[y * _width + x]);
                uint8_t red = 0;
                uint8_t blue = 0;
                uint8_t green = 0;

                if (iterations != myproj::Mandlebrot::MAX_ITERATIONS) {
                    double hue = 0.0;

                    for (int i = 0; i <= iterations; i++) {
                        hue += ((double)_histogram[i]) / _total;
                    }

                    blue = hue * 255;
                }

                _bitmap.setPixel(x, y, red, green, blue);
            }
        }
    }

    void FractalCreator::calculateTotalIterations() {
        for (int i = 0; i < myproj::Mandlebrot::MAX_ITERATIONS; i++) {
            _total += _histogram[i];
        }
    }

    void FractalCreator::addZoom(const Zoom& zoom) {
        _zoomList.add(zoom);
    }

    void FractalCreator::writeBitmap(std::string fileName) {
        _bitmap.write("test.bmp");
    }
}
