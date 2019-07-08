#include "mex.h"
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    double  *h, *alpha, *h_temp;
    int num_columns, num_rows;
    double theta;    
    num_columns = (int) mxGetN(prhs[0]); //cols
    num_rows    = (int) mxGetM(prhs[0]); //rows
    h           = (double *)mxGetData(prhs[0]);
    theta       = (double)*mxGetPr(prhs[1]);
    /* Initial zeros matrix*/
    plhs[0]   = mxCreateDoubleMatrix(num_rows, num_columns, mxREAL);  alpha = mxGetPr(plhs[0]);
    //////////////Compute alpha/////////
    // there are num_rows many elements in each column
    // and num_columns many rows. Matlab stores column first.
    // h[0] ... h[num_rows-1] == h(:,1)
    int idx; // to help make code cleaner
    for (int column_idx=0; column_idx < num_columns; column_idx++) {
        //iterate over each column
        for (int row_idx=0; row_idx < num_rows-1; row_idx++) {// exclude h(end,row_idx)
            //for each row in a column do
            idx = num_columns * column_idx + row_idx;
            alpha[idx]= theta * (h[idx+1] + h[idx]);
        }
    }
    //the last column wasn't modified and set to 0 upon initialization.
    //set it now
    for(int rows = 0; rows < num_rows; rows++) {
        alpha[num_columns*rows+(num_rows-1)] = theta * h[num_columns*rows+(num_rows-1)];
    }
}
