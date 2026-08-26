#include <iostream>
using namespace std;

int main() {
    int testCaseCount; // 原 T：測試資料的組數

    cin >> testCaseCount;

    // 處理每一組測試資料
    for (int caseIdx = 0; caseIdx < testCaseCount; caseIdx++) {
        int totalDays, partyCount, hartalInterval;
        
        cin >> totalDays >> partyCount; // 原 N (總天數) 和 P (政黨數量)
        
        // 原 days 陣列：用來標記哪一天會罷工 (0 代表正常，1 代表罷工)
        // 開大小為 totalDays + 1 是為了讓天數可以直接對應 1 ~ totalDays 的索引
        int isHartalDay[totalDays + 1] = {0}; 
        int lostWorkdays = 0;                  // 原 total：總共損失的工作日天數
        
        // 讀取每個政黨的罷工週期
        for (int partyIdx = 0; partyIdx < partyCount; partyIdx++) {
            cin >> hartalInterval; // 原 hi：該政黨每隔幾天罷工一次
            
            // 從第 hartalInterval 天開始，每隔 hartalInterval 天標記一次罷工日
            for (int day = hartalInterval; day <= totalDays; day += hartalInterval) {
                
                // 排除週末：
                // 題目規定第 1 天是星期日 (Sunday)，所以：
                // day % 7 == 6 代表星期五 (Friday)
                // day % 7 == 0 代表星期六 (Saturday)
                if (day % 7 == 6 || day % 7 == 0) {
                    continue; // 週末不計入工作日損失，直接跳過
                }
                
                // 如果這一天之前還沒被其他政黨標記過罷工
                if (isHartalDay[day] == 0) {
                    lostWorkdays++;        // 損失工作日 + 1
                    isHartalDay[day] = 1;  // 標記這一天已經算過罷工了 (避免重複計算)
                }
            }
        }
        
        // 輸出這組測試資料總共損失的工作日
        cout << lostWorkdays << endl;
    }

    return 0;
}