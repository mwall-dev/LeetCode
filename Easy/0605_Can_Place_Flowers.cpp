/*
    Approach:
        - Iterate though array.
        - If 0 then check if you have come from a 1 or 0 and if next is a 0. 
        - If so then make a 1.
        
    Sloppy, optimise.
    
    
    
    Approach 2: Stop when you reach n.
    

00111100



*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1) {
            if(flowerbed[0] == 0 && n <= 1) return true;
            else if(flowerbed[0] == 1 && n <= 0) return true;
            else return false;
        }
        
        for(int i = 0; i < )
    }
    
    
};



/*


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev = 0;
        int new_flowers = 0;
        if(flowerbed.size() == 1) {
            if(flowerbed[0] == 0 && n <= 1) return true;
            else if(flowerbed[0] == 1 && n <= 0) return true;
            else return false;
        }
        for(int i = 0; i < flowerbed.size() - 1; ++i) {
            if(flowerbed[i] == 0 && prev == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                ++new_flowers;
            }
            prev = flowerbed[i];
        }
        if(flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) {
            ++new_flowers;
        }
        std::cout << new_flowers;
        return n <= new_flowers;
    }
};


*/
