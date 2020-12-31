/// Source : https://leetcode.com/problems/avoid-flood-in-the-city/
/// Author : liuyubobobo
/// Time   : 2020-06-20

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Using HashMap for full lake and TreeSet for empty indice
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        vector<int> res(rains.size(), INT_MIN);
        unordered_map<int, int> full;
        set<int> empty_index;
        for(int i = 0; i < rains.size(); i ++){
            if(rains[i] > 0){
                int index = rains[i];
                if(full.count(index)){
                    if(empty_index.empty()) return {};

                    int t = full[index];
                    set<int>::iterator iter = empty_index.lower_bound(t);
                    if(iter == empty_index.end()) return {};

                    res[*iter] = index;
                    empty_index.erase(iter);
                }
                res[i] = -1;
                full[index] = i;
            }
            else empty_index.insert(i);
        }
        
        for(int& e: res) if(e == INT_MIN) e = 1;
        return res;
    }
};


void print_vec(const vector<int>& v){
    if(!v.size()) cout << "{}";
    else for(int e: v) cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> rains1 = {1,2,3,4};
    print_vec(Solution().avoidFlood(rains1));
    // -1 -1 -1 -1

    vector<int> rains2 = {1,2,0,0,2,1};
    print_vec(Solution().avoidFlood(rains2));
    // -1,-1,2,1,-1,-1

    vector<int> rains3 = {1,2,0,1,2};
    print_vec(Solution().avoidFlood(rains3));
    // {}

    vector<int> rains4 = {69,0,0,0,69};
    print_vec(Solution().avoidFlood(rains4));
    // -1,69,1,1,-1

    vector<int> rains5 = {10,20,20};
    print_vec(Solution().avoidFlood(rains5));
    // {}

    vector<int> rains6 = {0,1,1};
    print_vec(Solution().avoidFlood(rains6));
    // {}

    return 0;
}
