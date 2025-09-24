// 443. String Compression

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Note: The characters in the array beyond the returned length do not matter and should be ignored.

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int compress(vector<char>& chars){
    int idx = 0;

    for(int i =0; i < chars.size(); i++){
        char ch = chars[i];
        int count = 0;

        while(i < chars.size() && ch == chars[i]){
            count++; i++;
        }

        if(count == 1){
            chars[idx++] = ch;
        }else{
            chars[idx++] = ch;
            string str = to_string(count);
            for(char c : str){
                chars[idx++] = c;
            }
        }
        i--;
    }

    chars.resize(idx);
    return idx;
}

int main(){
    vector<char> chars = {'a','a','a','b','b','c','c','c'};

    cout<<"Size of comressed array : "<<compress(chars)<<endl;

    for(char ch : chars){
        cout<<ch<<" ";
    }
    cout<<endl;
}