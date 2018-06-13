/// Source : https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/
/// Author : liuyubobobo
/// Time   : 2018-06-12

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// HashMap
/// Time Complexity: O(max(l1, l2) * s), where s is the average length of string
/// Space Complexity: O(l1 * s)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

        unordered_map<string, int> map;
        for(int i = 0 ; i < list1.size() ; i ++)
            map[list1[i]] = i;

        int min_sum = INT_MAX;
        vector<string> res;
        for(int i = 0 ; i < list2.size() ; i ++)
            if(map.find(list2[i]) != map.end()){
                if(map[list2[i]] + i < min_sum){
                    res.clear();
                    res.push_back(list2[i]);
                    min_sum = map[list2[i]] + i;
                }
                else if(map[list2[i]] + i == min_sum){
                    res.push_back(list2[i]);
                }
            }

        return res;
    }
};


void print_vec(const vector<string>& vec){
    for(const string& s: vec)
        cout << s << " ";
    cout << endl;
}

int main() {

    vector<string> list1_1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list1_2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    print_vec(Solution().findRestaurant(list1_1, list1_2));

    vector<string> list2_1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2_2 = {"KFC", "Shogun", "Burger King"};
    print_vec(Solution().findRestaurant(list2_1, list2_2));

    return 0;
}