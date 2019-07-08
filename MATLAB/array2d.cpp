#include <mex.h>
#include <iostream>
using namespace std;
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) 
{ 
 //1.get pointer to input graph_list and allocate it    
    double *graph_list = mxGetPr(prhs[0]);
    mwSize mrows = mxGetM(prhs[0]);
    mwSize ncols = mxGetN(prhs[0]);  
    cout<< mrows<<" rows\n";
    cout<< ncols<<" cols\n";
    int mm, nn;
    for (nn=0;nn<ncols;nn++) {
        for (mm=0;mm<mrows;mm++){
            cout << graph_list[nn*(mrows) +mm]  <<"\n";            
        }
    }     
}
