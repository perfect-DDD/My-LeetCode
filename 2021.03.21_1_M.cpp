//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
//
//进阶：
//一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
//一个简单的改进方案是使用 O(m  + n) 的额外空间，但这仍然不是最好的解决方案。
//你能想出一个仅使用常量空间的解决方案吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/set-matrix-zeroes
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
#include <vector>
using namespace std;

class mySolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();//行
        int n = matrix[0].size();//列
        vector<bool> row(m, false);//行
        vector<bool> column(n, false);//列

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                row[i] = row[i] || (matrix[i][j] == 0 ? true : false);
                column[j] = column[j] || (matrix[i][j] == 0 ? true : false);
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = (row[i] == true || column[j] == true) ? 0 : matrix[i][j];
    }
};

class bestSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) isCol = true;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (isCol) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

//void main() {
//    vector<vector<int>> matrix = {
//        {1,1,1},
//        {1,0,1},
//        {1,1,1},
//    };
//    mySolution mytest;
//    mytest.setZeroes(matrix);
//}
