// https://leetcode-cn.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size(), n = image[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j < n/2) swap(image[i][j], image[i][n - 1 - j]);
                image[i][j] = 1 - image[i][j];
            }
        }
        return image;
    }
};