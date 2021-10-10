/// Source : https://leetcode.com/problems/integer-to-english-words/
/// Author : liuyubobobo
/// Time   : 2021-10-10

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(log(num))
/// Space Complexity: O(1)
class Solution {

private:
    const string nums[20] = {
            "Zero", "One", "Two", "Three", "Four",
            "Five", "Six", "Seven", "Eight", "Nine",
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    const string nums10[10] = {
            "Zero", "Ten", "Twenty", "Thirty", "Forty",
            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

public:
    string numberToWords(int num) {

        if(num == 0) return "Zero";

        vector<int> segs;
        while(num){
            segs.push_back(num % 1000);
            num /= 1000;
        }

        string res = "";
        for(int i = segs.size() - 1; i >= 0; i --){
            res += numberToWords(segs[i], i);
            while(res.back() == ' ') res.pop_back();
            res += " ";
        }
        res.pop_back();
        return res;
    }

private:
    string numberToWords(int num, int p){

        if(num == 0) return "";

        string res = "";
        if(num >= 100) {
            res += nums[num / 100] + " Hundred ";
            num %= 100;
        }

        if(num > 0){
            if(num < 20) res += nums[num] + " ";
            else{
                res += nums10[num / 10] + " ";
                num %= 10;
                if(num > 0) res += nums[num] + " ";
            }
        }

        if(p == 1) res += "Thousand";
        if(p == 2) res += "Million";
        if(p == 3) res += "Billion";

        return res;
    }
};


int main() {

    cout << Solution().numberToWords(123) << endl;
    // One Hundred Twenty Three

    cout << Solution().numberToWords(12345) << endl;
    // Twelve Thousand Three Hundred Forty Five

    cout << Solution().numberToWords(1234567) << endl;
    // One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven

    cout << Solution().numberToWords(1234567891) << endl;
    // One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One

    cout << Solution().numberToWords(1000) << endl;
    // One Thousand

    cout << Solution().numberToWords(1000000) << endl;
    // One Million

    cout << Solution().numberToWords(1000010) << endl;
    // One Million Ten

    return 0;
}
