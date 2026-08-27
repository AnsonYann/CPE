#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// 遞迴函式：負責把數字拆解成 Bangla 單位
void bangla(long long n) {
    // 1. 處理 kuti (10^7 以上)
    if (n >= 10000000) {
        bangla(n / 10000000); // 超過千萬的部分，重新遞迴拆解！
        cout << " kuti";
        n %= 10000000;         // 留下不足千萬的餘數繼續處理
    }
    // 2. 處理 lakh (10^5 以上)
    if (n >= 100000) {
        bangla(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    // 3. 處理 hajar (10^3 以上)
    if (n >= 1000) {
        bangla(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    // 4. 處理 shata (10^2 以上)
    if (n >= 100) {
        bangla(n / 100);
        cout << " shata";
        n %= 100;
    }
    // 5. 處理剩下的個位/十位數
    if (n > 0) {
        cout << " " << n;
    }
}

int main() {
    // 加速 IO
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long num;
    int caseNum = 1;

    // 不斷讀取直到 EOF
    while (cin >> num) {
        // 格式要求：編號靠右對齊占 4 個字元
        cout << setw(4) << caseNum << ".";

        if (num == 0) {
            cout << " 0"; // 特殊情況：輸入本身就是 0
        } else {
            bangla(num);
        }
        
        cout << "\n";
        caseNum++;
    }

    return 0;
}