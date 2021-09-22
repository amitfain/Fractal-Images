// FractalImages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "FractalCreator.h"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const std::string FILE_NAME = "test.bmp";
    myproj::FractalCreator fractalCreator(WIDTH, HEIGHT);
    fractalCreator.addZoom(myproj::Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.addZoom(myproj::Zoom(312, HEIGHT - 304, 0.1));
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap(FILE_NAME);

    /*myproj::Bitmap bitmap(WIDTH, HEIGHT);
    std::unique_ptr<int[]> histogram(new int[myproj::Mandlebrot::MAX_ITERATIONS]{});
    std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});
    myproj::ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(myproj::Zoom(WIDTH / 2, HEIGHT / 2, 4.0/WIDTH));
    
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++){
            std::pair<double, double> fractle = zoomList.doZoom(x, y);

            uint8_t iteration = myproj::Mandlebrot::getIterations(fractle.first, fractle.second);
            fractal[y * WIDTH + x] = iteration;

            if (iteration != myproj::Mandlebrot::MAX_ITERATIONS) {
                histogram[iteration]++;
            }
        }
    }

    int total = 0;

    for (int i = 0; i < myproj::Mandlebrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int iterations = (fractal[y * WIDTH + x]);
            uint8_t red = 0;
            uint8_t blue = 0;
            uint8_t green = 0;

            if (iterations != myproj::Mandlebrot::MAX_ITERATIONS) {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++) {
                    hue += ((double)histogram[i]) / total;
                }

                blue = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }


    bitmap.write("test.bmp");*/

    std::cout << "finished " << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
