class Solution {
public:
    int countTriples(int n) {
        int triples = 0;
        auto c = 0.0;
        for(int a = 1; a < n; a++){
            for(int b = a; b < n; b++){
                c = sqrt((a*a) + (b*b));
                if(c <= n && floor(c) == c) triples+=2;
            }
        }
        return triples;
    }
};