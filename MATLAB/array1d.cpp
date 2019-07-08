// arrays example
#include <math.h>
#include <matrix.h>
#include <mex.h>
#include <iostream>
using namespace std;

int foo [] = {16, 2, 77, 40, 12071};
int n, result=0;

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  for ( n=0 ; n<5 ; ++n )
  {
    cout << foo[n];
    cout << " ";
    //result += foo[n];
  }
  //cout << result;
}