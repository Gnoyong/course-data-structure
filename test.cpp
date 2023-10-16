#include <iostream>
#include <vector>
#include <string>

using namespace std;

double f(int, int);

int main()
{
    cout << f(1, 10);
    cout << endl;
}

double f(int n, int k)
{
    double x = n;
    while (x < 2)
    {
        x = x / k;
    }
    return x;
}