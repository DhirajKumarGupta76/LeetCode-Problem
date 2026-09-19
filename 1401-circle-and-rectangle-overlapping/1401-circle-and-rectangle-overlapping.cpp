class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        int xi, yi;

        // Nearest x
        if (xCenter < x1)
            xi = x1;
        else if (xCenter > x2)
            xi = x2;
        else
            xi = xCenter;

        // Nearest y
        if (yCenter < y1)
            yi = y1;
        else if (yCenter > y2)
            yi = y2;
        else
            yi = yCenter;

        // Distance formula
        double distance = sqrt(
            (xi - xCenter) * (xi - xCenter) +
            (yi - yCenter) * (yi - yCenter)
        );

        return distance <= radius;
    }
};