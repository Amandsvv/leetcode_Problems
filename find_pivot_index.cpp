//In given array nums find a index from which left all indexes sum is eqaul to the right most all indexes
//if no such available return -1;

#include<iostream>
#include<vector>

using namespace std;

int pivotIdx(vector<int> &A){
    int leftSum = 0, rightSum = 0;
    for(int i =0; i< A.size(); i++){
        rightSum += A[i];
    }

    for(int i =0; i< A.size(); i++){
        rightSum -= A[i];
        if(leftSum == rightSum){
            return i;
        }
        leftSum += A[i];
    }

    return -1;
}

int main(){
    vector<int> A = {1,2,3};
    cout<<pivotIdx(A);
    return 0;
}