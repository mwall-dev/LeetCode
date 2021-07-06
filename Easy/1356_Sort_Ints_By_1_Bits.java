/*
    Notes:
        - Can use the sort method with a custom comparator which will
        sort based on number of bits but then ascending if same bit count.
        - Could cache numbers if large to improve performance.


    Approach : sort by bit count then ascending using lambda.









*/

// More concise and makes use of Java lib.
public int[] sortByBits(int[] arr) {
        Integer[] input = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(input, (a, b) -> Integer.bitCount(a) == Integer.bitCount(b) ? a - b : Integer.bitCount(a) - Integer.bitCount(b));
        return Arrays.stream(input).mapToInt(Integer::intValue).toArray();
}


/*
class Solution {
    public int[] sortByBits(int[] arr) {

        arr = Arrays.stream(arr)
               .boxed()
               .sorted((a, b) -> {

                    int aBits = countOneBits(a);
                    int bBits = countOneBits(b);

                    if(aBits == bBits) return a > b ? 1 : -1 ;
                    else return aBits > bBits ? 1 : -1;

                } )
                .mapToInt(i -> i)
               .toArray();
        return arr;
    }


    private int countOneBits(int x) {
        int count = 0;

        while(x > 0) {
            if((x & 1) == 1) ++count;
            x = x >> 1;
        }

        return count;
    }
}
*/