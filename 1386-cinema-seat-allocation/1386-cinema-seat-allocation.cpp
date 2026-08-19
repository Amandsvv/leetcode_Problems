class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& seats) {
        sort(seats.begin(), seats.end());
        // for(auto & vec : reservedSeats){
        //     cout<<vec[0]<< " " <<vec[1] << endl;
        // }
        int sz = seats.size(), idx = 0;
        int lastSeat = seats[sz-1][0];
        int ans = 0;
        for(int i = 1; i <= lastSeat; i++){
            if(seats[idx][0] > i){
                ans += 2;
            }else{
                vector<bool> alloted(11, false);
                while(idx < sz && seats[idx][0] == i){
                    alloted[seats[idx][1]] = true;
                    idx++;
                }
                bool left = (!alloted[2] && !alloted[3] && !alloted[4] && !alloted[5]);
                   
                bool middle = (!alloted[4] && !alloted[5] && !alloted[6] && !alloted[7]);

                bool right = (!alloted[6] && !alloted[7] && !alloted[8] && !alloted[9]);

                if(left && right){
                    ans+=2;
                }else if(left || right || middle){
                    ans++;
                }
            }
        }
        ans += (n - lastSeat) * 2;
        return ans;
    }
};