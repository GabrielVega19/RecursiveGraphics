// Copyright [2021] <Gabriel Vega>

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Triangle.h"

using std::cout;
using std::endl;
using std::stod;
using sf::RenderWindow;
using std::stoi;

void triangleFractal(int i, RenderWindow* window,
    double x, double y, double l) {

    Triangle triangle(x, y, l);
    window->draw(triangle);
    if (i > 0) {
        triangleFractal(i - 1, window, x - (l / 4),
            y - sqrt((3.0/16) * pow(l, 2)), l/2);
        triangleFractal(i - 1, window, x + l, y, l/2);
        triangleFractal(i - 1, window, x, y + sqrt(.75 * pow(l, 2)), l/2);
    }
    return;
}

int main(int argc, char* argv[]) {
    // sets up command line arguments
    if (argc != 3) {
        cout << "Incorrect number of arguments passed in." << endl;
        exit(1);
    }
    int N = stoi(argv[2]);
    double L = stod(argv[1]);
    if (L <= 0 || N <= 0) {
        cout << "Problem with one of the parameters passed." << endl;
    }

    // sets up variables for window loop
    RenderWindow window(sf::VideoMode(L * 3, L * 3), "TFractal Window");
    // window loop to check if it was closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // sets up the fractal triangle
        window.clear(sf::Color::White);
        triangleFractal(N, &window, L * (9.0/10), L, L);
        // displays the fractal triangle
        window.display();
    }
    return 0;
}
