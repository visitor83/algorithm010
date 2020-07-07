/*
 * @lc app=leetcode.cn id=74 lang=c
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int i, j, pivot;
    int tR, tC;
    bool found = false;

    if (matrixSize == 0 || !matrixColSize) {
        return false;
    }

    tR = matrixSize;
    tC = matrixColSize[0];
    i = 0;
    j = matrixColSize[0] - 1;
    while (i <  tR && j >= 0 ) {
        // 1, 3, 5, 7 : 找34 > 7 在7的下方， 7这一行排除掉
        // 20 比较 34， 34 > 20 ， 20这一行排除掉
        // 50 比较 34,  34 < 50 在左边
        // 选择 34 查找
        //printf("i %d, j %d", i, j);
        pivot = matrix[i] [j];  
        //printf("pivot %d\n", pivot);
        if (pivot == target) {
            found = true;
        } else if (pivot < target) {
            i++;
        } else {
        //else if (bound > target) {
            j--;
        }

        if (found) {
            break;
        }
    }
    return found;
}

