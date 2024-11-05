#include "Point.hpp"

namespace adas
{
    Point::Point(const int x, const int y) noexcept
    {
        this->x = x;
        this->y = y;
    }
    Point::Point(const Point &rhs) noexcept
    {
        this->x = rhs.GetX();
        this->y = rhs.GetY();
    }
    Point &Point::operator=(const Point &rhs) noexcept
    {
        this->x = rhs.GetX();
        this->y = rhs.GetY();
        return *this;
    }
    Point &Point::operator+=(const Point &rhs) noexcept
    {
        this->x += rhs.GetX();
        this->y += rhs.GetY();
        return *this;
    }
    Point &Point::operator-=(const Point &rhs) noexcept
    {
        this->x -= rhs.GetX();
        this->y -= rhs.GetY();
        return *this;
    }
    int Point::GetX(void) const noexcept
    {
        return x;
    }
    int Point::GetY(void) const noexcept
    {
        return y;
    }
}