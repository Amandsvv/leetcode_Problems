// 495. Teemo Attacking

// Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration 
// seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 
// 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration 
// seconds after the new attack.

// You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries
// [i], and an integer duration.

// Return the total number of seconds that Ashe is poisoned.

#include<iostream>
#include<vector>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
    int count = 0, n = timeSeries.size();

    for(int i = 0; i < n; i++){
        count+=duration;
        int range = timeSeries[i] + duration -1;
        if(i < n-1 &&  range >= timeSeries[i+1]){
            int de = range - timeSeries[i+1] + 1;
            count-=de;
        }
    }

    return count;
}

int main(){
    vector<int> nums = {1,4,5};
    int duration = 2;

    cout<< "Maximum seconds asies poisoned is : "<< findPoisonedDuration(nums,duration)<<endl;
    return 0;
}
