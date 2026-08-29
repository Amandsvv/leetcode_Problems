class Solution {
public:
    string intToRoman(int num) {
        string nums = to_string(num);
        int sz = nums.length();
        string ans = "";

        // auto strRep = [&](int digit, int place) -> string{
        //     if(place == 4){
        //         return string(digit, 'M');
        //     }else if(place == 3){
        //         if(digit == 0){
        //             return "";
        //         }else if(digit == 1 || digit == 2 || digit == 3){
        //             return string(digit, 'C');
        //         }else if(digit == 4){
        //             return "CD";
        //         }else if(digit == 5){
        //             return "D";
        //         }else if(digit == 6 || digit == 7 || digit == 8){
        //             return "D" + string(digit - 5, 'C');
        //         }else if(digit == 9){
        //             return "CM";
        //         }
        //     }else if(place == 2){
        //         if(digit == 0){
        //             return "";
        //         }else if(digit == 1 || digit == 2 || digit == 3){
        //             return string(digit, 'X');
        //         }else if(digit == 4){
        //             return "XL";
        //         }else if(digit == 5){
        //             return "L";
        //         }else if(digit == 6 || digit == 7 || digit == 8){
        //             return "L" + string(digit - 5, 'X');
        //         }else if(digit == 9){
        //             return "XC";
        //         }
        //     }else{
        //         if(digit == 0){
        //             return "";
        //         }else if(digit == 1 || digit == 2 || digit == 3){
        //             return string(digit, 'I');
        //         }else if(digit == 4){
        //             return "IV";
        //         }else if(digit == 5){
        //             return "V";
        //         }else if(digit == 6 || digit == 7 || digit == 8){
        //             return "V" + string(digit - 5, 'I');
        //         }else if(digit == 9){
        //             return "IX";
        //         }
        //     }
        //     return "";
        // };

        auto strRep = [](int digit, int place) -> std::string {
            // Row 0: Ones, Row 1: Tens, Row 2: Hundreds, Row 3: Thousands
            std::string roman[4][10] = {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"} // Assumes input up to 3999
            };

            // Convert your 1-based places (1,2,3,4) to 0-indexed arrays
            return roman[place - 1][digit];
        };

        for (int i = 0; i < sz; i++) {
            int digit = nums[i] - '0';
            ans += strRep(digit, sz - i);
        }
        return ans;
    }
};