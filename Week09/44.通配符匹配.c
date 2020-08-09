/*
 * @lc app=leetcode.cn id=44 lang=c
 *
 * [44] 通配符匹配
 */

// @lc code=start

int slen, plen;
bool Backtrace(char *s, char *p, int sdep, int pdep) {
    //printf("sdep %d, pdep %d\n", sdep, pdep);

    if (pdep == plen) {
        return sdep == slen ? true :false;
    }

    if (p[pdep] == '*') {
        for (int i = sdep; i <= slen; i++) {
            if ( Backtrace(s, p, i, pdep + 1)) {
                return true;
            }
        }
    }
    if ( sdep < slen  && (s[sdep] == p[pdep] || p[pdep] == '?')) {
        return Backtrace(s, p, sdep + 1, pdep + 1);
    }

    return false;
}

bool isMatch(char * s, char * p)
{
    slen = strlen(s);
    plen = strlen(p);

    return Backtrace(s, p, 0, 0);
}

// @lc code=end

