class Solution {
public:
    bool canAliceWin(int n) {
       bool wins = false;
        int needToPick = 10;
        while(n >= needToPick){
            n-=needToPick;
            needToPick--;
            wins = !wins;
        }
        return wins;
    }
};