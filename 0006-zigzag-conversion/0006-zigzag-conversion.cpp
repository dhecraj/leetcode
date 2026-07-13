#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Edge cases: if 1 row or string length is less than rows, no change needed
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        
        // Track strings for each individual row
        std::vector<std::string> rows(numRows);
        int current_row = 0;
        bool going_down = false;
        
        // Simulate the zigzag movement
        for (char c : s) {
            rows[current_row] += c;
            
            // Flip direction at the boundaries
            if (current_row == 0 || current_row == numRows - 1) {
                going_down = !going_down;
            }
            
            current_row += going_down ? 1 : -1;
        }
        
        // Combine all rows into a single string
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }
        
        return result;
    }
};
