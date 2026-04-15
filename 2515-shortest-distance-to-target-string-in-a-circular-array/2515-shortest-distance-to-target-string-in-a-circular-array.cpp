class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for(int i = 0; i <= n >> 1; i++){
            if(words[((startIndex + i)%n)] == target || words[((startIndex - i  + n)%n)] == target) return i;
        }
        return -1;
        // int a = 0, b = 0;

        // int i = startIndex, n = words.size();
        // do {
        //     if (words[i] == target)
        //         break;
        //     a++;
        //     i = (i + 1) % n;
        // } while (i != startIndex);

        // int j  = startIndex;
        // do {
        //     if (words[j] == target)
        //         break;
        //     b++;
        //     j = (j - 1 + n) % n;
        // } while (j != startIndex);

        // if(words[i] != target && words[j] != target) return -1;
        // return min(a,b);
    }
};