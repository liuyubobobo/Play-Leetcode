/// Source : https://leetcode.com/problems/lru-cache/
/// Author : liuyubobobo
/// Time   : 2021-11-24

import java.util.*;


/// Using Time Stamp
/// Time Complexity: init: O(1)
///                  get: O(logn)
///                  put: O(logn)
/// Space Complexity: O(n)
public class LRUCache {

    private int timestamp;
    private int cap;

    private HashMap<Integer, Integer> data;
    private HashMap<Integer, Integer> key2timestamp;
    private TreeMap<Integer, Integer> timestamp2key;

    public LRUCache(int capacity) {

        timestamp = 0;
        cap = capacity;

        data = new HashMap<>();
        key2timestamp = new HashMap<>();
        timestamp2key = new TreeMap<>();
    }

    public int get(int key) {

        if(data.containsKey(key)){
            int oldTimestamp = key2timestamp.get(key);
            timestamp2key.remove(oldTimestamp);

            key2timestamp.put(key, timestamp);
            timestamp2key.put(timestamp, key);
            timestamp ++;

            return data.get(key);
        }
        return -1;
    }

    public void put(int key, int value) {

        if(data.containsKey(key)){
            int oldTimestamp = key2timestamp.get(key);
            timestamp2key.remove(oldTimestamp);
        }

        data.put(key, value);

        key2timestamp.put(key, timestamp);
        timestamp2key.put(timestamp, key);
        timestamp ++;

        if(data.size() > cap){
            int removeTimestamp = timestamp2key.firstKey();
            int removeKey = timestamp2key.get(removeTimestamp);

            data.remove(removeKey);
            key2timestamp.remove(removeKey);
            timestamp2key.remove(removeTimestamp);
        }
    }

    public static void main(String[] args) {

        LRUCache lru = new LRUCache(2);
        lru.put(1, 1);
        lru.put(2, 2);
        System.out.println(lru.get(1)); // 1
        lru.put(3, 3);
        System.out.println(lru.get(2)); // -1
    }
}
