class Solution {
public:
    string intToRoman(int num) {
        string nums = to_string(num);
        int sz = nums.length();
        string ans = "";

        auto strRep = [&](int digit, int place) -> string{
            if(place == 4){
                return string(digit, 'M');
            }else if(place == 3){
                if(digit == 0){
                    return "";
                }else if(digit == 1 || digit == 2 || digit == 3){
                    return string(digit, 'C');
                }else if(digit == 4){
                    return "CD";
                }else if(digit == 5){
                    return "D";
                }else if(digit == 6 || digit == 7 || digit == 8){
                    return "D" + string(digit - 5, 'C');
                }else if(digit == 9){
                    return "CM";
                }
            }else if(place == 2){
                if(digit == 0){
                    return "";
                }else if(digit == 1 || digit == 2 || digit == 3){
                    return string(digit, 'X');
                }else if(digit == 4){
                    return "XL";
                }else if(digit == 5){
                    return "L";
                }else if(digit == 6 || digit == 7 || digit == 8){
                    return "L" + string(digit - 5, 'X');
                }else if(digit == 9){
                    return "XC";
                }
            }else{
                if(digit == 0){
                    return "";
                }else if(digit == 1 || digit == 2 || digit == 3){
                    return string(digit, 'I');
                }else if(digit == 4){
                    return "IV";
                }else if(digit == 5){
                    return "V";
                }else if(digit == 6 || digit == 7 || digit == 8){
                    return "V" + string(digit - 5, 'I');
                }else if(digit == 9){
                    return "IX";
                }
            }
            return "";
        };

        for(int i = 0; i < sz; i++){
            int digit = nums[i] - '0';
            ans += strRep(digit , sz - i); 
        }
        return ans;
    }
};