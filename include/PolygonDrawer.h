#ifndef POLYGONDRAWER_H
#define POLYGONDRAWER_H

#include <vector>
#include "Point.h"
#include "Color.h"
#include "Line.h"

class PolygonDrawer {
public:
    PolygonDrawer();

    ~PolygonDrawer();

    void drawPolygon(const std::vector<Point> &points, const Color &color);
};

#endif // POLYGONDRAWER_H
