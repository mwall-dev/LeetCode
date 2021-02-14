
/*
    Greedy Approach: X to Y
    Start from Y (the target)
    if Y < X just subtract dfference and that is answer.
    
    if Y > X: start at Y and go down to X .Always greedily divide by 2 if even. If odd than add 1.
    Then add difference at end.






*/






class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X == Y) return 0;
        else if(Y < X) return X - Y;


        else {
            int count = 0;
            while(Y > X) {
                if(Y % 2 == 0) Y /= 2;
                else Y += 1;

                ++count;
            }

            return count + (X - Y);
        }
    }
};



