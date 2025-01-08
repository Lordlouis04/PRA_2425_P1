#include "Square.h"

bool Square::check(const Point2D* vertices) {
    double side1 = Point2D::distance(vertices[0], vertices[1]);
    double side2 = Point2D::distance(vertices[1], vertices[2]);
    double side3 = Point2D::distance(vertices[2], vertices[3]);
    double side4 = Point2D::distance(vertices[3], vertices[0]);

    return (side1 == side2 && side2 == side3 && side3 == side4);
}

Square::Square() : Rectangle() {
    Point2D default_vertices[N_VERTICES] = {
        Point2D(-1, 1),
        Point2D(1, 1),
        Point2D(1, -1),
        Point2D(-1, -1)
    };

    set_vertices(default_vertices);
}

Square::Square(std::string color,  Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("vertices erroneos");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("vertices erroneos");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Shape::Square=  color: " << square.get_color()<< " Vertices= v0: " << square[0]<< " v1: " << square[1]<< " v2: " << square[2]<< " v3: " << square[3] << std::endl;
    return out;
}

// Imprime la representación del cuadrado
void Square::print() {
    std::cout << *this << std::endl;
}
