#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArr(vector<int> num){
    for(int el : num){
        cout<<el<<" ";
    }
    cout<<endl;
}
void solution1(vector<int> &nums1, int m, vector<int> &nums2, int n){
    for(int i = m ,j = 0; i<m+n && j < n; i++,j++){
        nums1[i] = nums2[j];
    }
    sort(nums1.begin(),nums1.end());
}

void solution2(vector<int> &A, int m, vector<int> &B, int n){
    int idx = m+n-1, i = m-1, j = n-1;

    while(i >=0 && j >=0){
        if(A[i] >= B[j]){
            A[idx--] = A[i--];
        }else{
            A[idx--] = B[j--];
        }
    }

    while(j>=0){
        A[idx--] = B[j--];
    }

}
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = 0, j = 0;

    while (nums1[i] != 0 &&  j<n)
    {
        if (nums1[i] == nums2[j])
        {
            nums1.pop_back();
            nums1.insert(nums1.begin() + (i + 1), nums2[j]);
            i += 2;
            j++;
        }
        else
        {
            i++;
        }

        printArr(nums1);
    }
    
    while(j < n){
        nums1[i++] = nums2[j++];
    }
}

int main()
{
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};

    int m = 3;
    int n = 3;
    
    merge(num1,m,num2,n);
    printArr(num1);

    return 0;
}