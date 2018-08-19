/// Source : https://leetcode.com/problems/boats-to-save-people/description/
/// Author : liuyubobobo
/// Time   : 2018-08-04
#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int res = 0;
        while(i <= j){
            if(i == j){
                res ++;
                break;
            }

            res ++;
            if(people[i] + people[j] <= limit){
                i ++;
                j --;
            }
            else
                j --;
        }
        return res;
    }
};


int main() {

    vector<int> people1 = {1, 2};
    cout << Solution().numRescueBoats(people1, 3) << endl; // 1

    vector<int> people2 = {3, 2, 2, 1};
    cout << Solution().numRescueBoats(people2, 3) << endl; // 3

    vector<int> people3 = {3, 5, 3, 4};
    cout << Solution().numRescueBoats(people3, 5) << endl; // 4

    return 0;
}