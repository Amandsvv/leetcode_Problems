#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

int distributeCandies(vector<int> &candyType)
{
    unordered_set<int> type;
    for (int candy : candyType)
    {
        type.insert(candy);
    }

    return type.size() <= candyType.size() / 2 ? type.size() : candyType.size() / 2;
}
int main()
{
    vector<int> a = {1,2,3,1,2,1,2};
    cout<<distributeCandies(a)<<endl;
}