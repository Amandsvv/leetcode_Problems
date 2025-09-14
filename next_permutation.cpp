// 31. Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

#include<iostream>
#include<vector>

using namespace std;

void revArr(vector<int> &A, int i, int j){
    while(i<=j){
        swap(A[i++],A[j--]);
    }
}

void findNextPer(vector<int> &A){
    int pivot = -1;
    int n =A.size();
    for(int i= n-2; i >= 0; i-- ){
        if(A[i] < A[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        revArr(A,0,n-1);
        return;
    }

    for(int i = n-1; i > pivot; i--){
        if(A[i] > A[pivot]){
            swap(A[pivot],A[i]);
            break;
        }
    }

    revArr(A,pivot+1,n-1);
}

int main(){
    vector<int> A = {1,2,3};
    findNextPer(A);

    for(int el: A){
        cout<<el<<" ";
    }
}