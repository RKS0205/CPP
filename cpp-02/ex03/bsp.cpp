#include "Point.hpp"

float area(float x1, float y1, float x2, float y2, float x3, float y3) {
	float area; 
	
	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
	if (area < 0)
		area *= -1.0;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float area1;
	float area2;
	float area3;
	float area_total;

	area1 = area(point.getX().toFloat(), point.getY().toFloat(),
					a.getX().toFloat(), a.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat());

	area2 = area(point.getX().toFloat(), point.getY().toFloat(),
					a.getX().toFloat(), a.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	area3 = area(point.getX().toFloat(), point.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	area_total = area(a.getX().toFloat(), a.getY().toFloat(),
					b.getX().toFloat(), b.getY().toFloat(),
					c.getX().toFloat(), c.getY().toFloat());

	if (area_total == (area1 + area2 + area3) && area_total != 0 &&\
					area1 != 0 && area2 != 0 && area3 != 0)
		return (true);
	else
		return (false);
}
