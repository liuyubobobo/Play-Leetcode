#include <iostream>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;


class Solution {

private:
    const int LIMIT = 1000;

public:
    int brokenCalc(int X, int Y) {

        if(X >= Y)
            return X - Y;

        unordered_map<int, int> visited;
        queue<int> q;

        visited[X] = 0;
        q.push(X);
        int res = INT_MAX;
        while(!q.empty()){

            int cur = q.front();
            int step = visited[cur];
//            cout << cur << " " << step << endl;
            q.pop();

            if(step > LIMIT)
                continue;

            if(cur == Y) return step;

            int next = 2 * cur;
            if(next > Y)
                res = min(res, step + 1 + (next - Y));
            else if(!visited.count(next))
                visited[next] = step + 1, q.push(next);

            if(cur && cur >= Y / 2){
                int next = cur - 1;
                if(next > 0 && !visited.count(next))
                    visited[next] = step + 1, q.push(next);
            }
        }

        return res;
    }
};

int main() {

    cout << Solution().brokenCalc(2, 3) << endl;
    // 2

    cout << Solution().brokenCalc(5, 8) << endl;
    // 2

    cout << Solution().brokenCalc(3, 10) << endl;
    // 3

    cout << Solution().brokenCalc(1024, 1) << endl;
    // 1023

    cout << Solution().brokenCalc(1, 1000000000) << endl;
    // ?

    return 0;
}