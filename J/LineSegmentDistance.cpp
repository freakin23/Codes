// Problem Link: https://open.kattis.com/problems/segmentdistance

#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;

    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }

    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }

    double dot(const Point& other) const {
        return x * other.x + y * other.y;
    }

    double cross(const Point& other) const {
        return x * other.y - y * other.x;
    }

    Point multiply(double scalar) const {
        return {x * scalar, y * scalar};
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }

    bool isZero() const {
        return std::abs(x) < 1e-9 && std::abs(y) < 1e-9;
    }
};

struct Line {
    Point a, b;

    Line(Point a, Point b) : a(a), b(b) {}

    // Calculate the minimum distance from this line segment to another line segment
    double distanceToLineSegment(Line& l) {
        if (doesIntersect(l)) return 0.0;

        // Compute all possible point-to-line-segment distances
        std::array<double, 4> distances = {
            distanceToPoint(l.a),
            distanceToPoint(l.b),
            l.distanceToPoint(a),
            l.distanceToPoint(b)
        };

        // Return the minimum distance
        return *std::min_element(distances.begin(), distances.end());
    }

    // Check if this line segment intersects with another line segment
    bool doesIntersect(const Line& l) {
        Point e = b - a;
        Point f = l.b - l.a;
        double cross_product = f.cross(e);

        // Parallel lines
        if (std::abs(cross_product) < 1e-9) return false;

        double y = (e.x * (l.a.y - a.y) + e.y * (a.x - l.a.x)) / cross_product;
        double z = (f.x * (a.y - l.a.y) + f.y * (l.a.x - a.x)) / -cross_product;

        // Check if intersection point is within the segments
        return (0.0 <= y && y <= 1.0) && (0.0 <= z && z <= 1.0);
    }

    // Calculate the distance from this line segment to a point
    double distanceToPoint(const Point& p) {
        Point d = b - a;

        // If segment is a point
        if (d.isZero()) return (p - a).length();

        double x = (p - a).dot(d) / d.dot(d);

        if (x < 0.0) {
            return (p - a).length();
        } else if (x > 1.0) {
            return (p - b).length();
        } else {
            Point projection = a + d.multiply(x);
            return (p - projection).length();
        }
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cout << fixed << setprecision(2);
    for (int i = 1; i <= test_case; i++) {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y; 
        Line line1(p1, p2);
        Line line2(p3, p4);
        cout << line1.distanceToLineSegment(line2) << '\n';
    }
    return 0;
}
