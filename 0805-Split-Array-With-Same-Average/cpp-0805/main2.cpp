/// Source : https://leetcode.com/problems/split-array-with-same-average/description/
/// Author : liuyubobobo
/// Time   : 2018-03-24

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <cassert>
#include <string>
#include <functional>
#include <utility>

using namespace std;

/// Meet in the Middle
///
/// Using a Custom Fraction class
/// The Algorithm is based on the official solution:
/// https://leetcode.com/problems/split-array-with-same-average/solution/
///
/// Time Complexity: O(2^(N/2))
/// Space Complexity: O(2^(N/2))

class Fraction{

private:
    int num, denom;

public:
    Fraction(int a = 0, int b = 1): num(a), denom(b){

        if(num == 0)
            denom = 1;
        else{
            if(denom < 0){
                num = -num;
                denom = -denom;
            }
            int g = gcd(abs(num), denom);
            num /= g;
            denom /= g;
        }
    }

    Fraction operator-(const Fraction& another){
        return Fraction(num * another.denom - another.num * denom,
                        denom * another.denom);
    }

    Fraction operator-(){
        return Fraction(-num, denom);
    }

    Fraction operator+(const Fraction& another){
        return Fraction(num * another.denom + another.num * denom,
                        denom * another.denom);
    }

    string hash_string() const{
        return to_string(num) + "/" + to_string(denom);
    }

private:
    int gcd(int a, int b){

        if(a < b)
            swap(a, b);
        // a > b
        if(a % b == 0)
            return b;
        return gcd(b, a % b);
    }
};

bool operator==(const Fraction& f1, const Fraction& f2) {
    return f1.hash_string() == f2.hash_string();
}

bool operator!=(const Fraction& f1, const Fraction& f2) {
    return !(f1 == f2);
}

// Custom Hash Function for Fraction
namespace std {
    template<>
    struct hash<Fraction> {
        size_t operator()(Fraction const &f) const noexcept {
            return std::hash<std::string>{}(f.hash_string());
        }
    };
}

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {

        int sum = accumulate(A.begin(), A.end(), 0);
        Fraction average(sum , A.size());

        vector<Fraction> v;
        for(int a: A)
            v.push_back(Fraction(a, 1) - average);

        unordered_set<Fraction> left_bag = get_sum(v, 0, A.size()/2);
        if(left_bag.find(Fraction(0, 1)) != left_bag.end())
            return true;

        unordered_set<Fraction> right_bag = get_sum(v, A.size()/2, A.size());
        if(right_bag.find(Fraction(0, 1)) != right_bag.end())
            return true;

        Fraction leftsum = accumulate(v.begin(), v.begin() + v.size() / 2, Fraction(0, 1));
        Fraction rightsum = accumulate(v.begin() + v.size() / 2, v.end(), Fraction(0, 1));
        for(Fraction num: left_bag)
            if(num != leftsum && right_bag.find(-num) != right_bag.end())
                return true;

        return false;
    }

private:
    unordered_set<Fraction> get_sum(const vector<Fraction>& v, int l, int r){

        unordered_set<Fraction> bag;
        for(int i = l ; i < r ; i ++){
            unordered_set<Fraction> new_bag;
            for(Fraction e: bag)
                new_bag.insert(e + v[i]);
            bag.insert(new_bag.begin(), new_bag.end());
            bag.insert(v[i]);
        }

        return bag;
    }
};

void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}


int main() {

    vector<int> A1 = {1,2,3,4,5,6,7,8};
    print_bool(Solution().splitArraySameAverage(A1));
    // true

    vector<int> A2 = {3, 1};
    print_bool(Solution().splitArraySameAverage(A2));
    // false

    vector<int> A3 = {18, 10, 5, 3};
    print_bool(Solution().splitArraySameAverage(A3));
    // false

    vector<int> A4 = {2,0,5,6,16,12,15,12,4};
    print_bool(Solution().splitArraySameAverage(A4));
    // true

    vector<int> A5 = {10,29,13,53,33,48,76,70,5,5};
    print_bool(Solution().splitArraySameAverage(A5));
    // true

    return 0;
}