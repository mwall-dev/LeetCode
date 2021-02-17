


/*
    Apporach:
    Sweep string.
    Have a current char.
    Starting index. Current index. 
    Upon change in character check if current - starting > 3 if so then add.

    time:O(N)
    spaceO(1)






*/

import java.util.*;



class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {

        int start = 0;
        int lastChar = s.charAt(0);
        List<List<Integer>> res = new ArrayList<>();
        int i = 0;
        for(; i < s.length(); ++i) {
            if(s.charAt(i) != lastChar) {

                if(i - start >= 3) {
                    ArrayList<Integer> newList = new ArrayList<Integer>();
                    newList.add(start);
                    newList.add(i-1);
                    res.add(newList);
                }
                lastChar = s.charAt(i);
                start = i;
            }

        }

        if(i - start >= 3) {
            ArrayList<Integer> newList = new ArrayList<Integer>();
            newList.add(start);
            newList.add(i-1);
            res.add(newList);
        }

        return res;
    }
}