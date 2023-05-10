class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int count = 1;
        int left = 0;
        int top = 0;
        int bottom = n - 1;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = count;
                count++;
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                matrix[j][right] = count;
                count++;
            }
            right--;

            if (top > bottom || left > right)
                break;

            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = count;
                count++;
            }
            bottom--;

            for (int j = bottom; j >= top; j--) {
                matrix[j][left] = count;
                count++;
            }
            left++;
        }
        return matrix;
    }
};