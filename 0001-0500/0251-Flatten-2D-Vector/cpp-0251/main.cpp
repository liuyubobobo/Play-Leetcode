#include <iostream>
#include <vector>

using namespace std;


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
