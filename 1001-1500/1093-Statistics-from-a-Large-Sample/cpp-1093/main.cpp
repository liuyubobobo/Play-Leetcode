/// Source : https://leetcode.com/problems/statistics-from-a-large-sample/
/// Author : liuyubobobo
/// Time   : 2019-06-22

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {

        vector<double> res;
        res.push_back(min_value(count));
        res.push_back(max_value(count));
        res.push_back(mean(count));
        res.push_back(median(count));
        res.push_back(mode(count));
        return res;
    }

private:
    int min_value(const vector<int>& count) {
        for(int i = 0; i <= 255; i ++)
            if(count[i])
                return i;
        return -1;
    }

    int max_value(const vector<int>& count) {
        for(int i = 255; i >= 0; i --)
            if(count[i])
                return i;
        return -1;
    }

    double mean(const vector<int>& count){

        long long sum = 0ll;
        int n = accumulate(count.begin(), count.end(), 0);

        for(long long i = 0; i <= 255; i ++)
            sum += i * count[i];
        return sum / (double)n;
    }

    double median(const vector<int>& count){

        int n = accumulate(count.begin(), count.end(), 0);
        if(n % 2) return get_num(count, n / 2);
        return (get_num(count, n / 2 - 1) + get_num(count, n / 2)) / 2.0;
    }

    int get_num(const vector<int>& count, int index){

        for(int i = 0; i <= 255; i ++)
            if(count[i] && index < count[i]) return i;
            else index -= count[i];
        return -1;
    }

    int mode(const vector<int>& count){

        int best = 0, res = -1;
        for(int i = 0; i <= 255; i ++)
            if(count[i] > best)
                best = count[i], res = i;
        return res;
    }
};


int main() {

    return 0;
}