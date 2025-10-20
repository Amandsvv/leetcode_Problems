// 599. Minimum Index Sum of Two Lists

// Given two arrays of strings list1 and list2, find the common strings with the least index sum.

// A common string is a string that appeared in both list1 and list2.

// A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j
// should be the minimum value among all the other common strings.

// Return all the common strings with the least index sum. Return the answer in any order.

#include <iostream>
#include <vector>
using namespace std;

vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
{
    vector<string> ans;
    int sum = INT32_MAX;
    for (int i = 0; i < list1.size(); i++)
    {
        for (int j = 0; j < list2.size(); j++)
        {
            if (list1[i] == list2[j])
            {
                if (sum > i + j)
                {
                    sum = i + j;
                    ans.clear();
                    ans.push_back(list1[i]);
                }
                else if (sum == i + j)
                {
                    ans.push_back(list1[i]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
    vector<string> ans = findRestaurant(list1,list2);

    for(string str : ans){
        cout<<str<<" ";
    }
    cout<<endl;
}