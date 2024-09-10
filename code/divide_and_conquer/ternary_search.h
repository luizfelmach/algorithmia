// Ternary search
// Very useful for finding max/min values between interval

// F(x)
// ^                 Goal
// |                o
// |             *     *
// |           *         *
// |         *             *
// |--------*----------------*-----------> x
// |   |   *                   *  |
// |   | *                        * F(r)
// |   * F(l)

double ternary_search(double l, double r) {
    double eps = 1e-9;
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);  // Return the maximum of f(x) in [l, r]
}