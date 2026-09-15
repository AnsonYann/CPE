// UVa 10252 - Common Permutation
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2, s;

    // 利用逗號運算子，每次讀取兩行輸入 (s1 與 s2)
    while (getline(cin, s1), getline(cin, s2))
    {   
        // 特殊狀況處理：原程式意圖防範空格字串 (注意：真正的空行長度為 0 ，即 "")
        if (s1 == " " || s2 == " ") {
            cout << " " << endl;
            continue;
        }

        // 雙重迴圈逐字比對 s1 與 s2
        for (int i = 0; i < s1.length(); i++)
        {
            for (int j = 0; j < s2.length(); j++)
            {
                // 當發現相同字元時
                if (s1[i] == s2[j]) {
                    s = s + s1[i]; // 將共同字元加進結果字串 s

                    // 擦掉該字元避免重複匹配
                    // ⚠️ 注意：erase 會導致字串長度變短與索引左移，可能引發漏查問題
                    s1.erase(i, 1); // 刪除 s1 中下標為 i 的 1 個字元
                    s2.erase(j, 1); // 刪除 s2 中下標為 j 的 1 個字元
                }
            }
        }

        // 將收集到的共同字元依字典序 (a-z) 由小到大排序
        sort(s.begin(), s.end());

        // 印出排序後的結果
        cout << s << endl;

        // 清空字串變數，避免影響下一組測試資料
        s1.clear(), s2.clear(), s.clear();
    }

    return 0;
}