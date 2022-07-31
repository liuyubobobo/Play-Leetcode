/// Source : https://leetcode.com/problems/flatten-2d-vector/
/// Author : liuyubobobo
/// Time   : 2022-07-30

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: init: O(n)
///                  query: O(1)
/// Space Complexity: O(n)
class Vector2D {

private:
    vector<int> data;
    int cur = -1;

public:
    Vector2D(vector<vector<int>>& vec){

        for(int i = 0; i < vec.size(); i ++)
            for(int e: vec[i]) data.push_back(e);
    }

    int next() {
        return data[++ cur];
    }

    bool hasNext() {
        return cur + 1 < data.size();
    }
};


int main() {

    return 0;
}
