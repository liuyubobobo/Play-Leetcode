/// Source : https://leetcode.com/problems/abbreviating-the-product-of-a-range/
/// Author : liuyubobobo
/// Time   : 2022-01-28

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


/// Big Number Simulation
/// Time Complexity: O(right - left)
/// Space Complexity: O(right - left)
class BigNumber{

private:
    long long pre = 0, suf = 0;
    const int d = 14;
    const long long pow10e14 = 100000000000000ll;

public:
    BigNumber(int num) : suf(num){};

    BigNumber& operator*=(int num){

        if(pre == 0){
            suf *= num;
            if(to_string(suf).size() <= d) return *this;

            pre = suf / pow10e14;
            suf %= pow10e14;
            return *this;
        }

        suf *= num;

        long long carry = suf / pow10e14;
        suf %= pow10e14;

        if(to_string(pre).size() < 19){
            pre *= num;
            pre += carry;
        }
        else pre *= num;

        string pres = to_string(pre);
        pre = stoll(pres.substr(0, d).c_str());

        return *this;
    }

    string str(){
        if(pre == 0){
            string sufs = to_string(suf);
            if(sufs.size() <= 10) return sufs;

            string a = sufs.substr(0, 5), b = sufs.substr(sufs.size() - 5);
            return a + "..." + b;
        }

        string pres = to_string(pre), sufs = to_string(suf);
        if(pres.size() + sufs.size() < 2 * d){
            string s = pres + sufs;
            string a = s.substr(0, 5), b = s.substr(s.size() - 5);
            return a + "..." + b;
        }

        return pres.substr(0, 5) + "..." + sufs.substr(sufs.size() - 5);
    }
};

class Solution {
public:
    string abbreviateProduct(int left, int right) {

        vector<int> nums;
        int twos = 0, fives = 0;
        for(int i = left; i <= right; i ++){
            nums.push_back(i);
            twos += get(i, 2);
            fives += get(i, 5);
        }

        int zeros = min(twos, fives);
        int cnt_twos = zeros, cnt_fives = zeros;
        for(int i = 0; i < nums.size() && (cnt_twos || cnt_fives); i ++){
            erase(nums[i], 2, cnt_twos);
            erase(nums[i], 5, cnt_fives);
        }

        BigNumber number(nums[0]);
        for(int i = 1; i < nums.size(); i ++)
            number *= nums[i];
        return number.str() + "e" + to_string(zeros);
    }

private:
    void erase(int& num, int p, int& cnt){
        while(cnt && num % p == 0)
            cnt --, num /= p;
    }

    int get(int num, int p){
        int res = 0;
        while(num % p == 0) res ++, num /= p;
        return res;
    }
};


int main() {

    cout << Solution().abbreviateProduct(1, 4) << endl;
    // 24e0

    cout << Solution().abbreviateProduct(2, 11) << endl;
    // 399168e2

    cout << Solution().abbreviateProduct(371, 375) << endl;
    // 7219856259e3

    cout << Solution().abbreviateProduct(981, 3082) << endl;
    // 34865...63744e524

    cout << Solution().abbreviateProduct(4838, 6186) << endl;
    // 36088...36896e337

    return 0;
}
