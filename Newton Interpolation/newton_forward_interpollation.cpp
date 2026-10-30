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
        for(int j=0; j<n-i; j++)
        {
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
    }
    cout << endl << "Forward Difference Table: " << endl;

    // Fixed printing loop for triangular table
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
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
    double p = (val - x[0]) / h;
    double term = 1;
    double solution = y[0][0];
    for(int i=1; i<n; i++)
    {
       term *= (p - (i - 1));
       solution += (term * y[0][i]) / factorial(i);
    }

    cout << fixed << setprecision(6);
    cout << "Final Solution: " << solution << endl;
    return 0;
}
