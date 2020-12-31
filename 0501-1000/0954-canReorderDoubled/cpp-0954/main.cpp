/// Source : https://leetcode.com/problems/array-of-doubled-pairs/
/// Author : liuyubobobo
/// Time   : 2018-12-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Greedy, from large absolute value to small absolute value
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {

        unordered_map<int, int> freq;
        for(int a: A)
            freq[a] ++;

        sort(A.begin(), A.end(), [](int a, int b){return abs(a) < abs(b);});
//        for(int a: A)
//            cout << a << " ";
//        cout << endl;

        for(int a: A){
            if(freq[a]){
                if(!freq[2 * a])
                    return false;
                freq[a] --;
                if(!freq[2 * a])
                    return false;
                freq[2 * a] --;
            }
        }
        return true;
    }
};


int main() {

    vector<int> A1 = {4, -2, 2, -4};
    cout << Solution().canReorderDoubled(A1) << endl;

    return 0;
}