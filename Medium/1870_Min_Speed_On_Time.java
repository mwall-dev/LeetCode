/*
    Notes:
        - v = x/t
        - so time = distance/speed (t = x/v)
        - The waiting can be ambigious.
        - From Example 3, it looks like if(dist.size() > (int)hour

    Approach : Brute Force.
        - Start at speed = 1 and simulate until you get an answer that works.
        - Simulation is like the question example.



    Approach : Optimised
        - Similar to brute force but instead of just checking speed + 1.
        - We start at midpoint  (1 + 10^7) / 2 and simulate.
            If time < hour than we want to go smaller speed to see if we can find a better min so look at
            If time > hour than we want to go larger speed as we are not making it on time.

            Use a binary search to get to these number. Note that we are not binary searching an array itself but actually just
            a range of numbers (which is what we actually normally do though as we binary search indices normally).

            Want to converge on answer.

        - From Example 3, it looks like if(dist.length > Math.round(hour)) than its impossible as the smallest time is 0.00001 and then needs to round up.


*/


class Solution {
    public int minSpeedOnTime(int[] dist, double hour) {

        if(dist.length > Math.ceil(hour)) return -1;


        int lowerSpeed = 1;
        int upperSpeed = 10000001;

        int result = 0;

        while(lowerSpeed < upperSpeed) {
            int currentSpeed = (lowerSpeed + upperSpeed) / 2;
            //System.out.format("Trying speed " + Integer.toString(currentSpeed) + "\n");
            if(canMakeInTime(dist, hour, currentSpeed)) {
                result = currentSpeed;
                // Try lower
                //System.out.println("Passed");
                upperSpeed = currentSpeed;
            }

            else {
                // Try higher.
                //System.out.println("Failed");

                lowerSpeed = currentSpeed + 1;
            }

        }

        return result;
    }

    private boolean canMakeInTime(int[] dist, double hour, int speed) {
        double time = 0; // Thankfully Math.ceil(0) won't put it to 1 (it would if it was 0.000000000001 or something).

        for(int trainDistance : dist) {
            time = Math.ceil(time); // Get to next integer hour before taking next train.
            time += trainDistance / (double)speed;
            if(time > hour) return false;
        }

        return true;
    }
}