class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLength = matrix.size();
        int columnLength = matrix[0].size();
        vector<int> spiral;
        int up = 0;
        int left = 0;
        int right = columnLength - 1;
        int down = rowLength - 1;

        while (spiral.size() < rowLength * columnLength) {

            for (int col = left; col <= right; col++) {
                spiral.push_back(matrix[left][col]);
            }

            // Increase up by 1 to avoid including top right member again
            for (int row = up + 1; row <= down; row++) {
                spiral.push_back(matrix[row][right]);
            }

            // To make sure we are in different row
            if (up != down) {
                // Decrease right by 1 to avoid including down right member again
                for (int col = right - 1; col >= left; col--) {
                    spiral.push_back(matrix[down][col]);
                }
            }

            // To make sure we are in different column
            if (left != right) {
                // Decrease down by 1 to avoid including down left member again
                for (int row = down - 1; row > up; row--) {
                    spiral.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            up++;
            down--;
        }

        return spiral;
    }
};