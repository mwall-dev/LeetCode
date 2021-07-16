/*
    Notes:
        - Need a data structure where we can search for a range and see if it overlaps other ranges.



    Approach : TreeMap of pairs.
        - Keeps things sorted.
        - when trying to add a new booking:
            - Iterate through each entry in TreeMap.
            - while(tryingToAdd.start > inMap.end) go next;
            - check for overlap if found bad one.
            - add if reaches end.
*/



public class MyCalendar {

    private TreeSet<Range> calender;


    // Immutable helper class for holding pairs the represent a range.
    class Range {
        private final int start;
        private final int end;

        Range(int start, int end) {
            if(start > end) throw new IllegalArgumentException();

            this.start = start;
            this.end = end;
        }

        public int start() {
            return start;
        }

        public int end() {
            return end;
        }


    }


    public MyCalendar() {
        // Custom comparator to sort by start time ascending.
        calender = new TreeSet<>((range1, range2) -> {
            return Integer.compare(range1.start(), range2.start());
        });
    }


    public boolean book(int start, int end) {

        Range newRange= new Range(start, end);
        Range floor = calender.floor(newRange); // If added to set, this is the below element (start time just less)
        Range ceiling = calender.ceiling(newRange); // If added to set, this is the next above element (start time just greater)

        // Do we start before the last tasks end time?
        if (floor != null && start < floor.end()) return false;
        // Do we end during/after the next start time?
        if (ceiling != null && ceiling.start() < end) return false;

        calender.add(newRange);
        return true;
    }




    @Override
    public String toString() {
        StringBuilder strBuild = new StringBuilder();
        strBuild.append("Calender: \n");

        for(Range range : calender) {
            strBuild.append(Integer.toString(range.start()) + " " +
                            Integer.toString(range.end()) + "\n");
        }

        return strBuild.toString();
    }

}
