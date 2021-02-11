/// Source : https://leetcode.com/problems/design-most-recently-used-queue/
/// Author : liuyubobobo
/// Time   : 2021-02-10

#include <iostream>
#include <vector>

using namespace std;


/// Using Arrays
/// Time Complexity: init: O(n)
///                  fetch: O(n)
/// Space Complexity: O(n)
class MRUQueue {

private:
    vector<int> q;

public:
    MRUQueue(int n) : q(n) {
        for(int i = 0; i < n; i ++) q[i] = i + 1;
    }

    int fetch(int k) {
        k --;
        int ret = q[k];
        for(int i = k + 1; i < q.size(); i ++)
            q[i - 1] = q[i];
        q.back() = ret;
//        for(int e: q) cout << e << " "; cout << endl;
        return ret;
    }
};


int main() {

    MRUQueue q(8);
    cout << q.fetch(3) << endl; // 3
    cout << q.fetch(5) << endl; // 6
    cout << q.fetch(2) << endl; // 2
    cout << q.fetch(8) << endl; // 2

    return 0;
}
