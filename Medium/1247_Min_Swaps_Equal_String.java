import javax.transaction.xa.XAException;

/*
    - Iterate through both strings.
    - Ignore matched positions
    - Base swaps:
       Case 1: xx,yy needs 1 swap
       Case 2: xy,yx needs 2 swaps
       Case 3: xx xy cant work


    -Apply case 1 as much as possible.
    Then case 2
    Then if still not equals then cant work.


    xxyyxyxyxx
    xyyxyxxxyx


    


012 34 56 78 9    
xxy xy yx xy x
xyy xy xx xy x


CODE BELOW IS USELESS THIS QUESTION IS RIDICULOUS 
JUST A MATH TRICK
    public int minimumSwap(String s1, String s2) {
        int x1 = 0; // number of 'x' in s1 (skip equal chars at same index)
		int y1 = 0; // number of 'y' in s1 (skip equal chars at same index)
		int x2 = 0; // number of 'x' in s2 (skip equal chars at same index)
		int y2 = 0; // number of 'y' in s2 (skip equal chars at same index)

        for(int i = 0; i < s1.length(); i ++){
            char c1 = s1.charAt(i);
            char c2 = s2.charAt(i);
            if(c1 == c2){ // skip chars that are equal at the same index in s1 and s2
                continue;
            }
            if(c1 == 'x'){
                x1 ++;
            }else{
                y1 ++;
            }
            if(c2 == 'x'){
                x2 ++;
            }else{
                y2 ++;
            }
        } // end for
        
        // After skip "c1 == c2", check the number of  'x' and 'y' left in s1 and s2.
        if((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0){
            return -1; // if number of 'x' or 'y' is odd, we can not make s1 equals to s2
        }
        
        int swaps = x1 / 2 + y1 / 2 + (x1 % 2) * 2;
        // Cases to do 1 swap:
        // "xx" => x1 / 2 => how many pairs of 'x' we have ?
        // "yy" => y1 / 2 => how many pairs of 'y' we have ?
        // 
        // Cases to do 2 swaps:
        // "xy" or "yx" =>  x1 % 2
                 
        return swaps;        
    } 




*/

class Solution {
    public int minimumSwap(String s1, String s2) {
        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();
        
        int swaps = 0;

        // Look for xx and yy on both strings
        for(int i = 0; i < s1.length() - 1; ++i) {
            if(str1[i] == str1[i+1] && str2[i] == str2[i+1] && str1[i] != str2[i]) {
                char temp = str1[i];
                str1[i] = str2[i+1];
                str2[i + 1] = temp;
                ++swaps;
                System.out.println("1st");
                System.out.println("At index: " + i);
                i+=1;

            }   
            
        }

        for(int i = 0; i < s1.length() - 1; ++i) {
            if(str1[i] != str1[i+1] && str2[i] != str2[i+1] && str1[i] != str2[i]) {
                char temp = str1[i];
                str1[i] = str1[i+1];
                str1[i+1] = temp;
                swaps+=2;
                System.out.println("2nd");

                System.out.println("At index: " + i);

                i+=1;
            }   
        }


        s1 = new String(str1);
        s2 = new String(str2);
        System.out.println(s2);
        System.out.println(s1);
        if(!s1.equals(s2)) return -1;
        else return swaps;
    }


}