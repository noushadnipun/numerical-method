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

    double x[n], y[n][n];

    // Initialize array with 0
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            y[i][j] = 0;

    cout << endl << "X points: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> x[i];
    }
    cout << endl << "Y points: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> y[i][0];
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    cout << endl << "Backward Difference Table: " << endl;

    // Fixed printing loop for triangular table
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout << y[i][j] << '\t';
        }
        cout << endl;
    }

    cout << endl;

    double val;
    cout << "Enter the interpolation value : ";
    cin >> val;

    double h = x[1] - x[0];
    double p = (val - x[n-1]) / h;
    double term = 1;
    double solution = y[n-1][0];
    for(int i=1; i<n; i++)
    {
       term *= (p + (i - 1));
       solution += (term * y[n-1][i]) / factorial(i);
    }

    cout << fixed << setprecision(6);
    cout << "Final Solution: " << solution << endl;
    return 0;
}
