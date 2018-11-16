#include<iostream>
#include<vector>

using namespace std;

void saxpy_parallel(vector<int> &y,
    vector<int> x,
    int a,
    size_t n)
{
    size_t i;

    #pragma omp parallel for schedule(dynamic) default(none) private(i) shared(a, n, x, y)
    for(i = 0; i < n; i++)
    {
        y[i] = a * x[i] + y[i];
    }
}