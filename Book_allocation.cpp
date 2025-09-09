//Given "N" no of books each ith value of the array[i] states the ith book's Page Number
//Alocate books to M Students such that maximum number of pages allocated to a student is minimum

// Points to keep in mind is : 

// --each book shouuld be allocated to a student
// --each student has to be allocated at least one book 
// --Alootment should be in contiguous manner

// calculate and return that possible number

#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> nums, int n, int m, int maxAllocation){
    int students = 1, pages = 0;
    for(int i = 0; i<n; i++){
        if(nums[i] > maxAllocation) return false;
        if(pages + nums[i] <= maxAllocation){
            pages+=nums[i];
        }else{
            students++;
            pages = nums[i];
        }
    }
    return students == m?true:false;
}

int minPages(vector<int> nums,int n, int m){
    int sum = 0;
    for(int i =0; i<n; i++){
        sum+=nums[i];
    }

    int st = 0,end = sum,ans = -1;
    if(m>n) return ans;

    while(st<=end){
        int mid = st + (end-st)/2;

        if(isValid(nums,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }

    return ans;
}

int main(){
    vector<int> Books = {2,1,3,4};
    int n = Books.size(), m = 2;

    cout<<minPages(Books,n,m);

    return 0;
}