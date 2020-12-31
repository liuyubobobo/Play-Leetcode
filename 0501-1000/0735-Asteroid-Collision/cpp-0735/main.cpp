/// Source : https://leetcode.com/problems/swap-nodes-in-pairs/description/
/// Author : liuyubobobo
/// Time   : 2017-11-25

#include <iostream>
#include <vector>

using namespace std;


/// Using Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        if(asteroids.size() == 0)
            return asteroids;

        vector<int> res;
        for(int i = 0; i < asteroids.size() ; ){
            int asteroid = asteroids[i];
            if(res.empty() || sign(asteroid) == sign(res.back())){
                res.push_back(asteroid);
                i ++;
            }
            else if(sign(asteroid) > 0){
                res.push_back(asteroid);
                i ++;
            }
            else if(abs(res.back()) > abs(asteroid))
                i ++;
            else if(abs(res.back()) == abs(asteroid)){
                res.pop_back();
                i ++;
            }
            else
                res.pop_back();
        }

        return res;
    }

private:
    bool sign(int x){
        return x > 0 ? true : false;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> asteroids1 = {5, 10, -5};
    printVec(Solution().asteroidCollision(asteroids1));
    // 5, 10

    // ---

    vector<int> asteroids2 = {8, -8};
    printVec(Solution().asteroidCollision(asteroids2));
    // empty

    // ---

    vector<int> asteroids3 = {10, 2, -5};
    printVec(Solution().asteroidCollision(asteroids3));
    // 10

    return 0;
}