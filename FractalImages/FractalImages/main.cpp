// FractalImages.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bitmap.h"
#include "Mandlebrot.h"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    myproj::Bitmap bitmap(WIDTH, HEIGHT);

    double minX = 999999;
    double maxX = -999999;
    double minY = 999999;
    double maxY = -999999;
    
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++){
            double xFractle = (x - (double)WIDTH / 2 - 150) / ((double)HEIGHT / 2);
            double yFractle = (y - (double)HEIGHT / 2) / ((double)HEIGHT / 2);

            if (xFractle < minX) minX = xFractle;
            if (xFractle > maxX) maxX = xFractle;

            if (yFractle < minY) minY = yFractle;
            if (yFractle > maxY) maxY = yFractle;

            bitmap.setPixel(x, y, myproj::Mandlebrot::getIterations(xFractle, yFractle), 0, 0);
        }
    }


    bitmap.write("test.bmp");
    std::cout << "finished" << std::endl;
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
