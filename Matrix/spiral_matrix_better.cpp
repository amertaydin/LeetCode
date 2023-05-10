class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLength = matrix.size();
        int columnLength = matrix[0].size();
        vector<int> spiral;
        int top = 0;
        int left = 0;
        int right = columnLength - 1;
        int bottom = rowLength - 1;
        cout << right << bottom;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                spiral.push_back(matrix[top][i]);
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                spiral.push_back(matrix[j][right]);
            }
            right--;

            if ((top > bottom) || (left > right))
                break;
            
            for (int i = right; i >= left; i--) {
                spiral.push_back(matrix[bottom][i]);
            }
            bottom--;

            for (int j = bottom; j >= top; j--) {
                spiral.push_back(matrix[j][left]);
            }
            left++;  
        }
        return spiral;
    }
};