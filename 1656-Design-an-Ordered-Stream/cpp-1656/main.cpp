/// Source : https://leetcode.com/problems/design-an-ordered-stream/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class OrderedStream {

private:
    vector<string> data;
    int p;

public:
    OrderedStream(int n) : data(n, ""), p(0) { }

    vector<string> insert(int id, string value) {

        id --;
        data[id] = value;

        vector<string> res;
        while(p < data.size() && data[p] != "")
            res.push_back(data[p ++]);
        return res;
    }
};


int main() {
    
    return 0;
}
