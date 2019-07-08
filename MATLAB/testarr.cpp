#include "mex.h"
#include <stdlib.h>
#include <string.h>

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray* prhs[])
{
    // validate number of arguments
    if (nrhs != 0 || nlhs > 2) {
        mexErrMsgTxt("Wrong number of arguments");
    }

    // create C-array (or you can recieve this array from a function)
    int len = 5;
    double *arr = (double*) malloc(len*sizeof(double));
    for(int i=0; i<len; i++) {
        arr[i] = 10.0 * i;
    }

    // return outputs from MEX-function
    plhs[0] = mxCreateDoubleMatrix(1, len, mxREAL);
    memcpy(mxGetPr(plhs[0]), arr, len*sizeof(double));
    if (nlhs > 1) {
        plhs[1] = mxCreateDoubleScalar(len);
    }

    // dellocate heap space
    free(arr);
}