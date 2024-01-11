#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream circleFile("file1.txt");
    std::ifstream pointsFile("file2.txt");

    if (!circleFile.is_open() || !pointsFile.is_open()) {
        std::cerr << "Failed to open input files." << std::endl;
        return 1;
    }

    double centerX, centerY, radius;
    circleFile >> centerX >> centerY >> radius;

    double x, y;
    while (pointsFile >> x >> y) {
        double distance = hypot(x - centerX, y - centerY);
        if (distance < radius) {
            std::cout << "Точка (" << x << ", " << y << ") внутри окружности." << std::endl;
        }
        else if (distance == radius) {
            std::cout << "Point (" << x << ", " << y << ") лежит на окружности." << std::endl;
        }
        else {
            std::cout << "Point (" << x << ", " << y << ") снаружи окружности." << std::endl;
        }
    }

    circleFile.close();
    pointsFile.close();

    return 0;
}
