/// Source : https://leetcode.com/problems/sum-game/
/// Author : liuyubobobo
/// Time   : 2021-07-11

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc - Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool sumGame(string num) {

        int n = num.size();

        int leftsum = 0, left = 0;
        for(int i = 0; i < n / 2; i ++)
            if(num[i] == '?') left ++;
            else leftsum += (num[i] - '0');

        int rightsum = 0, right = 0;
        for(int i = n / 2; i < n; i ++)
            if(num[i] == '?') right ++;
            else rightsum += (num[i] - '0');

//        cout << left << " " << leftsum << " " << right << " " << rightsum << endl;

        if(leftsum >= rightsum)
            return solve(leftsum - rightsum, left, right);
        return solve(rightsum - leftsum, right, left);
    }

private:
    // sum + a? = b?
    bool solve(int sum, int a, int b){

//        cout << sum << " " << a << " " << b << endl;

        if((a + b) % 2) return true;

        if(a > b) return true;

        return (b - a) / 2 * 9 != sum;
    }
};


int main() {

    cout << Solution().sumGame("?3295???") << endl;
    // 0

    return 0;
}
