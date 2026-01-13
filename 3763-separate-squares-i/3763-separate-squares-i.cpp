class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        //arrange squares according to y axis --> sort Y ais 
        // binary search for Y values 
        double low= -1e9, high = -1e9;
        for (auto &sq : squares) {

            double y = sq[1];
            double side = sq[2];
            low = min(low, y);
            high = max(high, y + side);
        }
    /// internsting we didnt do low high because it is double not int and 
    // after  dividgin 60 times it is ebug that bcs 2^60 is nearly 0 even if y is 2^18 still enough precision 
        for (int iter = 0; iter < 60; iter++) {  // enough for double precision
            double mid = (low + high) / 2.0;

            double areaAbove = 0.0, areaBelow = 0.0;

            for (auto &sq : squares) {
                double y = sq[1];
                double side = sq[2];
                double top = y + side;

                if (mid <= y) {
                    // Entire square above
                    areaAbove += side * side;
                }
                else if (mid >= top) {
                    // Entire square below
                    areaBelow += side * side;
                }
                else {
                    // Square is cut by the line
                    areaAbove += (top - mid) * side;
                    areaBelow += (mid - y) * side;
                }
            }

            if (areaAbove > areaBelow) {
                low = mid;      // move line up
            } else {
                high = mid;     // move line down
            }
        }
        return (low + high) / 2.0;
    }
};