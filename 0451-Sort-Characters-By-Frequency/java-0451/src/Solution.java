/// Source : https://leetcode.com/problems/sort-characters-by-frequency/
/// Author : liuyubobobo
/// Time   : 2020-02-27

import java.util.ArrayList;
import java.util.Collections;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(256)
class Solution {

    private class Pair implements Comparable<Pair>{

        public char c;
        public int f;

        public Pair(char c, int f){
            this.c = c;
            this.f = f;
        }

        @Override
        public int compareTo(Pair another){
            return another.f - this.f;
        }
    }

    public String frequencySort(String s) {

        int[] freq = new int[256];
        for(char c: s.toCharArray())
            freq[c] ++;

        ArrayList<Pair> lst = new ArrayList<>();
        for(char c = 0; c < 256; c ++)
            if(freq[c] != 0)
                lst.add(new Pair(c, freq[c]));

        Collections.sort(lst);

        StringBuilder sb = new StringBuilder();
        for(Pair p: lst)
            for(int i = 0; i < p.f; i ++) sb.append(p.c);
        return sb.toString();
    }
}