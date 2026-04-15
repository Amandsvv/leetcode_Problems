class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int a = 0, b = 0;

        int i = startIndex, n = words.size();
        do {
            if (words[i] == target)
                break;
            a++;
            i = (i + 1) % n;
        } while (i != startIndex);

        int j  = startIndex;
        do {
            if (words[j] == target)
                break;
            b++;
            j = (j - 1 + n) % n;
        } while (j != startIndex);

        if(words[i] != target && words[j] != target) return -1;
        return min(a,b);
    }
};