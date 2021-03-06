#include "Range.h"
#include <glib.h>

Range::Range(double x, double y) {
	XOJ_INIT_TYPE(Range);

	this->x1 = x;
	this->x2 = x;

	this->y1 = y;
	this->y2 = y;
}

Range::~Range() {
	XOJ_RELEASE_TYPE(Range);
}

void Range::addPoint(double x, double y) {
	XOJ_CHECK_TYPE(Range);

	this->x1 = MIN(this->x1, x);
	this->x2 = MAX(this->x2, x);

	this->y1 = MIN(this->y1, y);
	this->y2 = MAX(this->y2, y);
}

double Range::getX() {
	XOJ_CHECK_TYPE(Range);

	return this->x1;
}

double Range::getY() {
	XOJ_CHECK_TYPE(Range);

	return this->y1;
}

double Range::getWidth() {
	XOJ_CHECK_TYPE(Range);

	return this->x2 - this->x1;
}

double Range::getHeight() {
	XOJ_CHECK_TYPE(Range);

	return this->y2 - this->y1;
}

double Range::getX2() {
	XOJ_CHECK_TYPE(Range);

	return this->x2;
}

double Range::getY2() {
	XOJ_CHECK_TYPE(Range);

	return this->y2;
}

