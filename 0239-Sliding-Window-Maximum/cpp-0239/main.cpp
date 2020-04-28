/// Source : https://leetcode.com/problems/sliding-window-maximum/description/
/// Author : liuyubobobo
/// Time   : 2017-11-22

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Using Index Max Heap
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

// 最大索引堆
template<typename Item>
class IndexMaxHeap{

private:
    Item *data;     // 最大索引堆中的数据
    int *indexes;   // 最大索引堆中的索引, indexes[x] = i 表示索引i在x的位置
    int *reverse;   // 最大索引堆中的反向索引, reverse[i] = x 表示索引i在x的位置

    int count;
    int capacity;

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftUp( int k ){

        while( k > 1 && data[indexes[k/2]] < data[indexes[k]] ){
            swap( indexes[k/2] , indexes[k] );
            reverse[indexes[k/2]] = k/2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    // 索引堆中, 数据之间的比较根据data的大小进行比较, 但实际操作的是索引
    void shiftDown( int k ){

        while( 2*k <= count ){
            int j = 2*k;
            if( j + 1 <= count && data[indexes[j+1]] > data[indexes[j]] )
                j += 1;

            if( data[indexes[k]] >= data[indexes[j]] )
                break;

            swap( indexes[k] , indexes[j] );
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

public:
    // 构造函数, 构造一个空的索引堆, 可容纳capacity个元素
    IndexMaxHeap(int capacity){

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for( int i = 0 ; i <= capacity ; i ++ )
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;
    }

    ~IndexMaxHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    // 返回索引堆中的元素个数
    int size(){
        return count;
    }

    // 返回一个布尔值, 表示索引堆中是否为空
    bool isEmpty(){
        return count == 0;
    }

    // 向最大索引堆中插入一个新的元素, 新元素的索引为i, 元素为item
    // 传入的i对用户而言,是从0索引的
    void insert(int i, Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );

        // 再插入一个新元素前,还需要保证索引i所在的位置是没有元素的。
        assert( !contain(i) );

        i += 1;
        data[i] = item;
        indexes[count+1] = i;
        reverse[i] = count+1;
        count++;

        shiftUp(count);
    }

    // 从最大索引堆中取出堆顶元素, 即索引堆中所存储的最大数据
    Item extractMax(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // 从最大索引堆中取出堆顶元素的索引
    int extractMaxIndex(){
        assert( count > 0 );

        int ret = indexes[1] - 1;
        swap( indexes[1] , indexes[count] );
        reverse[indexes[count]] = 0;
        reverse[indexes[1]] = 1;
        count--;
        shiftDown(1);
        return ret;
    }

    // 获取最大索引堆中的堆顶元素
    Item getMax(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    // 获取最大索引堆中的堆顶元素的索引
    int getMaxIndex(){
        assert( count > 0 );
        return indexes[1]-1;
    }

    // 看索引i所在的位置是否存在元素
    bool contain( int i ){
        assert( i + 1 >= 1 && i + 1 <= capacity );
        return reverse[i+1] != 0;
    }

    // 获取最大索引堆中索引为i的元素
    Item getItem( int i ){
        assert( contain(i) );
        return data[i+1];
    }

    // 将最大索引堆中索引为i的元素修改为newItem
    void change( int i , Item newItem ){

        assert( contain(i) );
        i += 1;
        data[i] = newItem;

        shiftUp( reverse[i] );
        shiftDown( reverse[i] );
    }

    void remove(int i){

        change(i, INT_MIN);

        i += 1;

        int pos = reverse[i];
        swap( indexes[pos] , indexes[count] );
        reverse[indexes[count]] = count;
        reverse[indexes[pos]] = pos;

        shiftDown( pos );
        shiftUp( pos );

        assert(reverse[i] == count);
        reverse[i] = 0;
        count--;
    }
};


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k == 0 || nums.size() == 0)
            return vector<int>();

        if(k == 1)
            return nums;

        IndexMaxHeap<int> ipq(nums.size());
        for(int i = 0 ; i < k - 1 ; i ++)
            ipq.insert(i, nums[i]);

        vector<int> res;
        for(int i = k - 1 ; i < nums.size() ; i ++){
            ipq.insert(i, nums[i]);
            res.push_back(ipq.getMax());

            assert(ipq.size() == k);
            ipq.remove(i - (k - 1));
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    print_vec(Solution().maxSlidingWindow(nums, 3));
    // 3 3 5 5 6 7

    return 0;
}