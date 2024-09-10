// Bisection Method
// Very useful for finding roots of a function

// F(x)
// ^     F(lo)
// |   *
// |   | *
// |   |  *
// |   |   *  Goal
// |--------O-------------------------> x
// |          *              |
// |            *            *
// |              *       *   F(hi)
// |                * * *

double bisection(double lo, double hi) {
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        double F   = f(mid);  // Declare a function
        if (F > 0)
            lo = mid;
        else
            hi = mid;
    }
    return lo;
}