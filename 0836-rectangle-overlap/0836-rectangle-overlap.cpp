class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 is completly left of rec2;
        if(rec1[2]<=rec2[0]) return false;

        //rec1 is completly right of rec2;
        if(rec2[2]<=rec1[0]) return false;

        //rect1 is completly below of rec2;
        if(rec1[1]>=rec2[3]) return false;

        //rect1 is completly above of rect2;
        if(rec2[1]>=rec1[3]) return false;
        else return true;


    }
};