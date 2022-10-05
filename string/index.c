/**
 * 串的模式匹配
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 普通的模式匹配
 * 对主串的每个字符作为子串的开头进行匹配
 * 对主串做大循环，每个字符的开头做子串长度的小循环
 * 匹配上字符了，两个串都走一步
 * 没匹配上字符，主串走一步，子串不动
 */
int queryIndex(String S, String T) {
    int sLength = S.length;
    int tLength = T.length;
    for (int i = 0; i < sLength; i++) {
        // 主串某个字符和子串第一个字符匹配上
        if (S[i] == T[0]) {
            int count = 1;
            for (int j = 1; j < tLength; j++) {
                if (s[i + 1] == T[j]) {
                    count++;
                } else {
                    continue;
                }
            }
        }
    }
}

int main() {
    return 0;
}