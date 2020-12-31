/// Source : https://leetcode.com/problems/map-sum-pairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-05

#include <iostream>
#include <unordered_map>

using namespace std;

/// Prefix HashMap + Brute Force
/// Time Complexity: insert: O(len(prefix)^2)
///                  sum: O(len(prefix))
/// Space Complexity: O(sum(len(wi)^2)) where wi is the length of the ith word.
class MapSum {

private:
    unordered_map<string, int> prefixScore;
    unordered_map<string, int> summap;
public:
    /** Initialize your data structure here. */
    MapSum() {
        summap.clear();
        prefixScore.clear();
    }

    void insert(string key, int val) {

        if(summap.find(key) == summap.end()){
            for(int i = 1 ; i <= key.size() ; i ++)
                prefixScore[key.substr(0, i)] += val;
        }
        else{
            for(int i = 1 ; i <= key.size() ; i ++)
                prefixScore[key.substr(0, i)] = val;
        }

        summap[key] = val;
    }

    int sum(string prefix) {
        return prefixScore[prefix];
    }
};

int main() {

    MapSum obj;
    obj.insert("apple", 3);
    cout << obj.sum("ap") << endl; // 3
    obj.insert("app", 2);
    cout << obj.sum("ap") << endl; // 5

    return 0;
}