/// Source : https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int n = answerKey.size();
        return max(get_res(n, answerKey, 'T', k), get_res(n, answerKey, 'F', k));
    }

private:
    int get_res(int n, const string answerKey, char c, int k){

        int res = 0, l = 0, r = -1, cur = 0;
        while(l < n){
            if(r + 1 < n && cur + (answerKey[r + 1] == c) <= k)
                cur += answerKey[++ r] == c;
            else
                cur -= answerKey[l ++] == c;
            res = max(res, r - l + 1);
        }
        return res;
    }
};


int main() {

    cout << Solution().maxConsecutiveAnswers("TTFF", 2) << endl;
    // 4

    cout << Solution().maxConsecutiveAnswers("TFFT", 1) << endl;
    // 3

    cout << Solution().maxConsecutiveAnswers("TTFTTFTT", 1) << endl;
    // 5

    return 0;
}
