// UVa 11332 - Summing Digits
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // 不斷讀入數字 n
    while (cin >> n)
    {
        // 題目規定：輸入為 0 時停止程式
        if (n == 0) break;

        int sum;

        // 外層迴圈：只要 n 還是兩位數以上 (>= 10)，就繼續把各數位相加
        while (n >= 10)
        {
            sum = 0; // 每一輪加總前，將 sum 清零

            // 內層迴圈：利用取餘數與除法，逐一剝離並加總 n 的每一個位數
            while (n != 0)
            {
                sum += n % 10; // 取出最右邊的個位數，加進 sum
                n /= 10;       // 砍掉最右邊的個位數
            }

            n = sum; // 將這一輪加總的新數字賦給 n，準備進行下一輪檢查
        }

        // 輸出最後剩下的一位數
        cout << n << endl;
    }

    return 0;
}