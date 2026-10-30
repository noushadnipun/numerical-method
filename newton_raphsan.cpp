#include <bits/stdc++.h>
using namespace std;

// Target function: f(x) = x * e^x - cos(x)
double f(double x) {
    return x * exp(x) - cos(x);
}

// Derivative function: f'(x) = e^x * (1 + x) + sin(x)
double df(double x) {
    return exp(x) * (1 + x) + sin(x);
}

int main() {
    double x0, x1, e;
    int max_iter;

    cout << "Enter the initial value: ";
    cin >> x0;

    cout << "Enter tolerance: ";
    cin >> e;

    cout << "Enter maximum iterations: ";
    cin >> max_iter;

    int step = 1;

    while(step <= max_iter) {
        if(df(x0) == 0.0) {
            cout << "Mathematical error (derivative is zero)." << endl;
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);

        cout << "Iteration " << step << ": x = " << setprecision(10) << x1 << endl;

        if(fabs(x1 - x0) < e) {
            cout << "\nConverged successfully!" << endl;
            break;
        }

        x0 = x1;
        step++;
    }

    cout << "Final Result: " << x1 << endl;
    return 0;
}
