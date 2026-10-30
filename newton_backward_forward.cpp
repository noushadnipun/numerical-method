#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int temp = 1;
    for(int i=1; i<=n; i++)
    {
        temp *= i;
    }
    return temp;
}

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[n], y_forward[n][n], y_backward[n][n];

    // Initialize arrays with 0
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            y_forward[i][j] = 0;
            y_backward[i][j] = 0;
        }
    }

    cout << endl << "X points: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }

    cout << endl << "Y points: " << endl;
    for(int i=0; i<n; i++)
    {
        double val;
        cin >> val;
        y_forward[i][0] = val;
        y_backward[i][0] = val;
    }

    // --- 1. FORWARD INTERPOLATION CALCULATION ---
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            y_forward[j][i] = y_forward[j+1][i-1] - y_forward[j][i-1];
        }
    }

    // --- 2. BACKWARD INTERPOLATION CALCULATION ---
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            y_backward[i][j] = y_backward[i][j-1] - y_backward[i-1][j-1];
        }
    }

    double val_f, val_b;
    cout << "\nEnter the interpolation value for Forward (e.g., 0.12): ";
    cin >> val_f;

    cout << "Enter the interpolation value for Backward (e.g., 0.26): ";
    cin >> val_b;

    cout << "\n========================================\n";
    cout << "       NEWTON'S FORWARD INTERPOLATION     \n";
    cout << "========================================\n";
    cout << "Forward Difference Table: \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            cout << y_forward[i][j] << '\t';
        }
        cout << endl;
    }

    double h = x[1] - x[0];
    double p_f = (val_f - x[0]) / h;
    double term_f = 1;
    double sol_f = y_forward[0][0];
    for(int i=1; i<n; i++)
    {
       term_f *= (p_f - (i - 1));
       sol_f += (term_f * y_forward[0][i]) / factorial(i);
    }

    cout << fixed << setprecision(6);
    cout << "Final Forward Solution for tan(" << val_f << "): " << sol_f << endl;

    cout << "\n========================================\n";
    cout << "      NEWTON'S BACKWARD INTERPOLATION     \n";
    cout << "========================================\n";
    cout << "Backward Difference Table: \n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << y_backward[i][j] << '\t';
        }
        cout << endl;
    }

    double p_b = (val_b - x[n-1]) / h;
    double term_b = 1;
    double sol_b = y_backward[n-1][0];
    for(int i=1; i<n; i++)
    {
       term_b *= (p_b + (i - 1));
       sol_b += (term_b * y_backward[n-1][i]) / factorial(i);
    }

    cout << "Final Backward Solution for tan(" << val_b << "): " << sol_b << endl;
    cout << "========================================\n";

    return 0;
}
