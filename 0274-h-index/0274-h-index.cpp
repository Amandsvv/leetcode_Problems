class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for(int h = n; h >= 0; h--){
            int i = 0;
            while(i < n && citations[i] >= h) i++;
            int pages = i;
            cout << "H : " << h << "Pages : "<<pages << endl;
            if(h <= pages) return h;
        }
        return 0;
    }
};