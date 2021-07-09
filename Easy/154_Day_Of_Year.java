/*
    Notes:
        - Leap year rule: if year % 4 == 0
                            if year % 100 == 0:
                                if(year % 400 == 0)
                                    is leap

                                else
                                    not leap

                            else
                                is leap


                        else no leap


    Approach:
        - Process string into year, month, day ints.
        - First determine if it is a leap year. (can skip this calculation maybe on some condition (e.g. month < 2 && day < 29)).
        - Cycle through months and add days making sure to add +1 if going through whole of feb.
        - Return num.

*/

class Solution {

    private final int[] daysInMonths =  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public int dayOfYear(String date) {

        // Parse string in.
        String[] dateSplit = date.split("-");
        int year = Integer.parseInt(dateSplit[0]);
        int month = Integer.parseInt(dateSplit[1]);
        int day = Integer.parseInt(dateSplit[2]);
        int dayOfYear = 0;

        // Sum all days in months up to the month given (non-inclusive).
        for(int m = 0; m < month - 1; ++m) {
            dayOfYear += daysInMonths[m];
        }

        dayOfYear += day;

        if(isLeapYear(year)) {
            if(month > 2) {
               ++dayOfYear;
            }
        }

        return dayOfYear;
    }



    private boolean isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) return year % 400 == 0;

            return true;
        }

        return false;
    }



}



