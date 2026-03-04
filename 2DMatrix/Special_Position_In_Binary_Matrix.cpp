#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool valid(int i , int j, vector<vector<int>>& mat){
        for(int k = 0; k < mat.size(); k++){
            if(k == i) continue;
            if(mat[k][j] == 1) return false;
        }

        for(int l = 0; l < mat[0].size(); l++){
            if(l == j) continue;
            if(mat[i][l] == 1) return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1 && valid(i,j,mat)) count++;
            }
        }
        return count;
    }
};
int main (){

}