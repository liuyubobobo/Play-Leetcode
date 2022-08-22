/// Source : https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {

        int need_energy = 0, need_exp = 0, cur_energy = initialEnergy, cur_exp = initialExperience;

        int n = energy.size();
        for(int i = 0; i < n; i ++){

            if(cur_energy <= energy[i]){
                need_energy += energy[i] + 1 - cur_energy;
                cur_energy = energy[i] + 1;
            }
            if(cur_exp <= experience[i]){
                need_exp += experience[i] + 1 - cur_exp;
                cur_exp = experience[i] + 1;
            }

            cur_exp += experience[i];
            cur_energy -= energy[i];
        }
        return need_exp + need_energy;
    }
};


int main() {

    vector<int> energy1 = {1, 4, 3, 2}, experience1 = {2, 6, 3, 1};
    cout << Solution().minNumberOfHours(5, 3, energy1, experience1) << '\n';
    // 8

    return 0;
}
