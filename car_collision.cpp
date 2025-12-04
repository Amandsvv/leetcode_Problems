#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        // Skip all leading 'L'
        while (i < n && s[i] == 'L') i++;

        // Skip all trailing 'R'
        while (j >= 0 && s[j] == 'R') j--;

        int collisions = 0;
        // Count all R and L in the remaining part
        for (; i <= j; i++) {
            if (s[i] == 'R' || s[i] == 'L')
                collisions++;
        }

        return collisions;
    }
};

int main (){

}