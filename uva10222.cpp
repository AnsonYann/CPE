// UVa 10222 - Decode the Mad man
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 依序建立美式鍵盤的按鍵地圖 (注意反斜線需要寫成 '\\' 進行轉義)
    string s1 = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string s2;

    // 不斷讀取一整行的輸入，直到檔案結束 (EOF)
    while (getline(cin, s2))
    {
        // 逐一檢查該行字串中的每一個字元
        for (int i = 0; i < s2.length(); i++) 
        {   
            // 1. 大寫轉小寫：若為大寫字母，先轉成小寫以符合 s1 鍵盤地圖
            if (s2[i] >= 'A' && s2[i] <= 'Z') 
                s2[i] = tolower(s2[i]); 

            // 2. 特殊字元直接印出：ASCII 32 代表空格 (' ')，ASCII 10 代表換行 ('\n')
            if (s2[i] == 32 || s2[i] == 10) { 
                cout << s2[i];
            }
            // 3. 一般字元位移校正：
            // s1.find(s2[i]) 找出該字元在鍵盤上的位置，向前退 2 格 (-2) 即可還原原字
            else { 
                cout << s1[s1.find(s2[i]) - 2];
            }
        }
        // 每處理完一行，輸出換行符號
        cout << "\n";
    }

    return 0;
}