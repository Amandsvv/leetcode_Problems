class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> ans(n);
        for(auto & card : deck){
            ans[q.front()] = card;
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};