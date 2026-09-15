// UVa 10252 - Common Permutation
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 宣告變數儲存輸入的兩列字串
    string s1, s2;

    // 使用 getline 逐行讀取，條件使用 && 保證兩行都成功讀到才進入迴圈
    // 此寫法能完美相容長度為 0 的「空字串 (Empty Line)」
    while (getline(cin, s1) && getline(cin, s2)) {
        
        // 宣告兩個長度為 26 的頻率陣列並初始化為 0
        // count1[0] 代表 'a' 在 s1 的次數，count1[25] 代表 'z' 的次數
        int count1[26] = {0}, count2[26] = {0};

        // 統計 s1 裡每個小寫字母出現的次數
        for (char c : s1) if (c >= 'a' && c <= 'z') count1[c - 'a']++;
        
        // 統計 s2 裡每個小寫字母出現的次數
        for (char c : s2) if (c >= 'a' && c <= 'z') count2[c - 'a']++;

        // 依據字典序 0~25 (即 'a'~'z') 依序檢查 26 個字母
        for (int i = 0; i < 26; i++) {
            
            // 取兩字串中該字母出現頻率的最小值 (即兩者的共同交集數量)
            int common = min(count1[i], count2[i]);
            
            // 根據交集數量，連續印出 common 次該字母
            for (int k = 0; k < common; k++) {
                cout << (char)('a' + i);
            }
        }
        
        // 每一組測試資料結束後印出換行
        cout << "\n";
    }
    return 0;
}