#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // return 0 if any of the number is going to be zero
        int n1 = num1.size(), n2 = num2.size();
        vector<int> res(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string result = "";
        for (int num : res) {
            if (!(result.empty() && num == 0)) result += to_string(num);
        }
        return result.empty() ? "0" : result;
    }
};

int main (){
    string s1 = "124";
    string s2 = "7813";
    auto obj = Solution();
    cout<<obj.multiply(s1,s2)<<endl;
}