/// Source : https://leetcode.com/problems/first-unique-number/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


/// Using HashMap + Queue
/// Time Complexity: init: O(n)
///                  showFirstUnique: O(1)
///                  add: O(n), amortized: O(1)
/// Space Complexity: O(n)
class FirstUnique {

private:
    unordered_map<int, bool> is_unique;
    queue<int> q;

public:
    FirstUnique(vector<int>& nums) {

        for(int num: nums) add(num);
    }

    int showFirstUnique() {
        if(!q.empty()) return q.front();
        return -1;
    }

    void add(int num) {

        if (!is_unique.count(num)) is_unique[num] = true;
        else is_unique[num] = false;

        if(is_unique.count(num) && is_unique[num])
            q.push(num);

        while(!q.empty() && is_unique.count(q.front()) && !is_unique[q.front()])
            q.pop();
    }
};


int main() {

    return 0;
}
