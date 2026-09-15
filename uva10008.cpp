// UVa 10008 - What's Cryptanalysis?
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, max = 0; // T: 輸入行數, max: 紀錄出現次數最多的字母頻率
    cin >> T;
    getchar(); // 濾掉輸入 T 後產生的換行符 ('\n')，避免影響第一次 getline 讀取

    int table[26] = {0}; // 宣告長度 26 的陣列並初始化為 0，對應 A-Z 26 個字母的出現次數

    // 處理 T 行輸入
    while (T--)
    {
        string s;
        getline(cin, s); // 讀取一整行的字串 (包含空格與標點符號)

        // 統計該行中每個字母的出現次數
        for (int i = 0; i < s.length(); i++)
        {
            // 處理大寫字母 'A'~'Z'
            if ('A' <= s[i] && s[i] <= 'Z') {
                table[s[i] - 'A']++; // 將 'A'~'Z' 對應到索引 0~25 並加 1
                if (table[s[i] - 'A'] > max) {
                    max = table[s[i] - 'A']; // 即時更新出現次數的最大值
                }
            }
            // 處理小寫字母 'a'~'z' (不分大小寫，統計到同一個位置)
            if ('a' <= s[i] && s[i] <= 'z') {
                table[s[i] - 'a']++; // 將 'a'~'z' 對應到索引 0~25 並加 1
                if (table[s[i] - 'a'] > max) {
                    max = table[s[i] - 'a']; // 即時更新出現次數的最大值
                }
            }
        }
    }

    // --- 輸出處理 (雙層迴圈達成排序效果) ---
    // 外層迴圈 j：代表「出現次數」，從最高頻率 (max) 遞減到 1，保證「次數由大到小」
    for (int j = max; j >= 1; j--) { 
        // 內層迴圈 k：代表「字母索引」，從 0 ('A') 遞增到 25 ('Z')，保證「次數相同時，字母由小到大」
        for (int k = 0; k <= 25; k++) {
            // 如果字母 k 的出現次數剛好等於目前的頻率 j
            if (table[k] == j) {
                // 將索引 k 轉回大寫字元印出，並印出對應的次數 j
                cout << char(k + 'A') << " " << j << "\n";
            }
        }
    }

    return 0;
}