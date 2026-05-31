class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        long long cal_mass = mass;
        for(int el : ast){
            if(cal_mass < el) return false;
            cal_mass+=el;
        }
        return true;
    }
};