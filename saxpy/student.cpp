#include<iostream>
#include<vector>

using namespace std;

void saxpy_parallel(vector<int> &y,
    vector<int> x,
    int a,
    size_t n)
{
	#pragma omp parallel for
    for(size_t i = 0; i < n; i++)
    {
        y[i] = a * x[i] + y[i];
    }
}