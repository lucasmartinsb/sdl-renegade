#include "PolygonDrawer.h"

#include <vector>
#include "Point.h"
#include "Color.h"

PolygonDrawer::PolygonDrawer() {
    // ctor
}

PolygonDrawer::~PolygonDrawer() {
    // dtor
}

void PolygonDrawer::drawPolygon(const std::vector<Point> &points, const Color &color) {
    if (points.size() < 2) {
        return;
    }

    for (size_t i = 0; i < points.size() - 1; ++i) {
        Line line = Line(points[i], points[i + 1], color);
        line.draw();
    }

    // Desenhar linha de fechamento entre o último e o primeiro ponto
    Line closingLine = Line(points.back(), points.front(), color);
    closingLine.draw();
}
