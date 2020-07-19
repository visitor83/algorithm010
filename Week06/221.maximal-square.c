/*
 * @lc app=leetcode.cn id=221 lang=c
 *
 * [221] 最大正方形
 */

// @lc code=start
/*
 * 1. 最优子结构, 问题最优解包含子问题最优解, 用来决策
 * 2. 重叠子问题
 * 3. 无后效性: 推到后面阶段状态，只关心前面阶段状态。
 *              某阶段状态一旦确认，不受后面阶段决策影响。
 * dp[i][j] - 以[i,j] 为右下角，且只包含1的最大正方形边长
1.子结构 :  从左上角开始， 左到右，上到下，这么走 **无后效性** 
            dp [i-1][j] -- 已经求过了?
            dp [i][j]  = 1 :   
                加入 - dp[i-1][j-1] = 1 , dp [i-1][j] =1, dp[i][j-1] = 1
                                        -------------+-------------------
                                                     |
                                                已经求过了
                不加入： dp[i][j] = 0 ||  dp [i-1][j] = 0 || dp[i][j-1] = 0 ?  那这个面积是0

            是全1 的右下角 
 */
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, cur;
    int **dp;
    int maxSide = 0;

    if (!matrixSize  || !matrix) {
        return 0;
    }
    const int R = matrixSize, C = matrixColSize[0];
    dp = calloc(  (R+1),  sizeof(int*) );
    for (i = 0; i < R + 1; i++) {
        dp[i] = calloc(C + 1, sizeof (int));
    }
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++ ) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    cur = fmin(dp[i-1][j] ,  dp[i][j-1]);
                    dp[i][j] = fmin(cur, dp[i-1][j-1]) + 1;
                    //maxSide = fmax(cur, maxSide);
                }
                maxSide = fmax(dp[i][j], maxSide);
            }
        }
    }
    return maxSide * maxSide;
}

int maximalSquare2(char** matrix, int matrixSize, int* matrixColSize)
{
    int i, j, ans;

    if (!matrixSize  || !matrix) {
        return 0;
    }

    const int ROW = matrixSize, COL = matrixColSize[0];
    ans = 0;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (matrix[i][j] != '1') {
                continue;
            }
            // 找到左上角，计算最大可取周长
            int excpectSize = fmin(ROW - i, COL - j);
            int k;
            ans = fmax(ans, 1);
            for (int r = 1; r < excpectSize; r++) {
                bool found = true;
                // 以列 递增 比对斜对角线上row的点 == 1，
                // 求当前最大的正方形的边长 maxlen
                if (matrix[i+r][j+r] == '0') {
                    found = false;
                    break;
                } 

                //新增右一列， 下一行间是否都是1, 是则更新最大值
                for (k = 0 ; k  <  r; k++) {
                    // i要加上r 
                    if ( matrix[i + r ] [j + k] == '0'  ||
                            matrix[i+k][j + r ] == '0'
                       ) {
                        found = false;
                        break;
                    }
                }

                if (found) {
                    ans = fmax(ans, r + 1  );
                } else {
                    break;
                }
            }
            //printf(" maxside %d\n", ans);
        }
    }
    return ans * ans;
}

// @lc code=end

