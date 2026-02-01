// 3829. Design Ride Sharing System
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// A ride sharing system manages ride requests from riders and availability from drivers. Riders request rides, and drivers become available over time. The system should match riders and drivers in the order they arrive.

// Implement the RideSharingSystem class:

// RideSharingSystem() Initializes the system.
// void addRider(int riderId) Adds a new rider with the given riderId.
// void addDriver(int driverId) Adds a new driver with the given driverId.
// int[] matchDriverWithRider() Matches the earliest available driver with the earliest waiting rider and removes both of them from the system. Returns an integer array of size 2 where result = [driverId, riderId] if a match is made. If no match is available, returns [-1, -1].
// void cancelRider(int riderId) Cancels the ride request of the rider with the given riderId if the rider exists and has not yet been matched.
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class RideSharingSystem {
private:
    queue<int> rider;
    queue<int> driver;
public:
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> ans = {-1, -1};
        int a;
        if(!rider.empty()){
            a = rider.front();
        }else{
            return ans;
        }
        int b;
        if(!driver.empty()){
            b = driver.front();
        }else{
            return ans;
        }
        rider.pop(); driver.pop();
        return {b,a};
    }
    
    void cancelRider(int riderId) {
        queue<int> newRider;
        while(!rider.empty()){
            int curr = rider.front();
            rider.pop();

            if(curr != riderId){
                newRider.push(curr);
            }
        }
        rider = newRider; 
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
int main (){

}