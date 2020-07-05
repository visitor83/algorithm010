/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start

bool Change(int *coins, int start, int aim)
{
    for (int j = start ; j <= 3; j++ ) {
        if (coins[j] >=  aim) {
            coins[j] -= aim;
            return true;
        }
    }

    return false;
}

bool lemonadeChange(int* bills, int billsSize)
{
    int coins[] = {0, 0, 0,0 };

    for (int i = 0; i < billsSize; i++) {
        //printf("bills %d : 20-%d, 10-%d, 5-%d\n", bills[i], coins[1], coins[2], coins[3]);
        if (bills[i] == 20) {
            if (!Change(coins, 2, 10) || !Change(coins, 3, 5)) {
                return false;
            }
            coins[1] += 20;
        }  else if (bills[i] == 10) {
            if (!Change(coins,3, 5)) {
                return false;
            }
            coins[2] += 10;
        } else if (bills[i] == 5) {
            coins[3] += 5;
        }
    }

    return true;
}
// @lc code=end

