/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-03-23

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Multiplication Simulation
/// Time Complexity: O(K)
/// Space Complexity: O(K)
class Solution {
public:
    int smallestRepunitDivByK(int K) {

        if(K % 2 == 0 || K % 5 == 0) return -1;

        unordered_set<int> visited;

        int left = 0, len = 0;
        while(true){

            int i = 0;
            for(i = 0; i <= 9; i ++)
                if((K * i + left) % 10 == 1){
                    left = (K * i + left) / 10;
                    len ++;
                    break;
                }

            if(i == 10) return -1;
            if(left == 0) return len;

            if(visited.count(left)) break;
            visited.insert(left);
        }
        return -1;
    }
};

int main() {

    cout << Solution().smallestRepunitDivByK(3) << endl;

    return 0;
}