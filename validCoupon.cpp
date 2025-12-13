#include<iostream>
#include<vector>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validCode(string str) {
        if (str.empty()) return false;

        for (char ch : str) {
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9') ||
                ch == '_') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    bool validLine(string str) {
        vector<string> validString = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };
        return find(validString.begin(), validString.end(), str) != validString.end();
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        
        // Priority order for business lines
        unordered_map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        // Store valid coupons as (businessPriority, code)
        vector<pair<int, string>> validCoupons;

        for (int i = 0; i < code.size(); i++) {
            if (validCode(code[i]) &&
                validLine(businessLine[i]) &&
                isActive[i]) {

                validCoupons.push_back({
                    priority[businessLine[i]],
                    code[i]
                });
            }
        }

        // Sort by businessLine priority, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        // Extract only codes
        vector<string> ans;
        for (auto &p : validCoupons) {
            ans.push_back(p.second);
        }

        return ans;
    }
};

int main (){

}