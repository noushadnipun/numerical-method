#include <bits/stdc++.h>
using namespace std;

double f(double x){
  //return (x*x*x) - (2*x) - 5;
  return exp(-x) * cos(x) - (x * x * x) + 2 * x - 1;

}

int main(){

 double x1, x2, solution, error, temp;
 while(1){
    cout << "Enter two numbers" << endl;

    cin >> x1 >> x2;

    if(f(x1) * f(x2) < 0){
        if(f(x1) > 0){
            swap(x1, x2);
        }
        break;
    }
 }

 temp= x2;

 for (int i=0; i < 100; i++){
    solution = (x1+x2)/2;

    cout << i+ 1 << ".Solution " << setprecision(10) << solution << endl;

    if(f(solution)== 0){
            break;
     }
    else if(f (solution)<0)
    {

        x1=solution;
    }
    else {
        x2 = solution;
    }
    error = fabs(solution-temp);
    temp = solution;
    cout << i +1 << ". Error " << error << endl;
    if(error<0.000001){
        break;
    }
 }
 cout << "final result: " << solution << endl;
 return 0;

}
