#include <bits/stdc++.h>

class Solution {
public:
    //Problem 1 : 3127. Make a Square with the Same Color
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int colors = 0;
                if (grid[i][j] == 'B') {
                    colors++;
                }
                else
                    colors--;
                if (grid[i + 1][j] == 'B') {
                    colors++;
                }
                else
                    colors--;
                if (grid[i][j + 1] == 'B') {
                    colors++;
                }
                else
                    colors--;
                if (grid[i + 1][j + 1] == 'B') {
                    colors++;
                }
                else
                    colors--;
                if (abs(colors) >= 2)
                    return true;
            }

        }
        return false;
    }

    //problem 2 : 3128. Right Triangles
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>inRows(n);
        vector<int>inCols(m);

        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) cnt++;
            }
            inRows[i] = cnt;
        }
        for(int j=0; j<m; j++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(grid[i][j] == 1) cnt++;
            }
            inCols[j] = cnt;
        }

        long long ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans += ((inRows[i]-1) * (inCols[j]-1));
                }
            }
        }

        return ans;
    }


};