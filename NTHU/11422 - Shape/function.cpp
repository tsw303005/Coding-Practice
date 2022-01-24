#include "function.h"
#include <cmath>

namespace oj {
    double getTriangleArea(double a, double b, double c) {
        double s = (a + b + c) / 2;
        double sa = s - a;
        double sb = s - b;
        double sc = s - c;

        return sqrt(s*sa*sb*sc);
    }

    Triangle::Triangle(double edge1, double edge2, double edge3) {
        if (edge1 <= 0.0 || edge2 <= 0.0 || edge3 <= 0.0) edge1 = edge2 = edge3 = 0.0;
        else if (!(edge1 + edge2 > edge3 && edge2 + edge3 > edge1 && edge1 + edge3 > edge2)) {
            edge1 = edge2 = edge3 = 0.0;
        }
        this->edge1 = edge1;
        this->edge2 = edge2;
        this->edge3 = edge3;
        this->setArea(getTriangleArea(edge1, edge2, edge3));
        this->setPerimeter(edge1+edge2+edge3);
    }

    Rectangle::Rectangle(double width, double height) {
        if (width <= 0.0 || height <= 0.0) width = height = 0.0;
        this->width = width;
        this->height = height;
        this->setArea(this->width*this->height);
        this->setPerimeter(2*(this->width+this->height));
    }

    Circle::Circle(double radius, double pi) {
        if (radius <= 0.0 || pi <= 0.0) pi = radius = 0.0;
        this->radius = radius;
        this->pi = pi;
        this->setArea(this->radius*this->radius*this->pi);
        this->setPerimeter(2*this->radius*this->pi);
    }
}