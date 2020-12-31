/// Source : https://leetcode.com/problems/numbers-with-1-repeated-digit/
/// Author : liuyubobobo
/// Time   : 2019-03-16

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Combination Mathematics
/// Time Complexity: O(log(N)^2)
/// Space Complexity: O(logN)
class Solution {
public:
    int numDupDigitsAtMostN(int N) {

        vector<int> diff(10, 0);
        for(int i = 1; i <= 9; i ++)
            diff[i] = get_diff(i);
        for(int i = 1; i < 10; i ++) diff[i] += diff[i - 1];
//        for(int e: diff) cout << e << " "; cout << endl;

        vector<int> power10(10, 1);
        for(int i = 1; i < 10; i ++) power10[i] = power10[i - 1] * 10;
//        for(int e: power10) cout << e << " "; cout << endl;

        vector<int> num;
        while(N) num.push_back(N % 10), N /= 10;
        reverse(num.begin(), num.end());
//        for(int e: num) cout << e << " "; cout << endl;

        int res = power10[num.size() - 1] - 1 - diff[num.size() - 1];
//        cout << res << endl;

        unordered_set<int> digits;
        for(int i = 0; i < num.size(); i ++){

            if(i == num.size() - 1){
                for(int d = 0; d <= num[i]; d ++)
                    if(digits.count(d)) res ++;
                break;
            }
            else if(num[i]){
                int tres = (num[i] - (i == 0)) * power10[num.size() - 1 - i];
                if(tres){
                    tres -= howmanydiff(num.size() - i, digits, num[i], i != 0);
                    res += tres;
                }
            }

            if(!digits.count(num[i]))
                digits.insert(num[i]);
            else{
                res += 1 + get_num(num, i + 1);
                break;
            }
        }
        return res;
    }

private:
    int howmanydiff(int n, const unordered_set<int>& digits, int first, bool canZero){

        int res = 0;
        for(int i = canZero ? 0 : 1; i < first; i ++)
            if(!digits.count(i)) res ++;
        n --;

        int cur = 10 - (digits.size() + 1);
        while(n --)
            res *= cur--;
        return res;
    }

    int get_num(const vector<int>& num, int s){
        int res = 0;
        for(int i = s; i < num.size(); i ++)
            res = res * 10 + num[i];
        return res;
    }

    int get_diff(int n){

        int res = 9;
        n --;

        int cur = 9;
        while(n --) res *= cur --;
        return res;
    }
};


int main() {

    cout << Solution().numDupDigitsAtMostN(20) << endl; // 1
    cout << Solution().numDupDigitsAtMostN(100) << endl; // 10
    cout << Solution().numDupDigitsAtMostN(1000) << endl; // 262
    cout << Solution().numDupDigitsAtMostN(11) << endl; // 1
    cout << Solution().numDupDigitsAtMostN(101) << endl; // 11
    cout << Solution().numDupDigitsAtMostN(110) << endl; // 12

    return 0;
}