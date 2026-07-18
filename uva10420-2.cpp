#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n; // 讀入總共有幾行資料

    map<string, int> counts; // 建立字典：國家(string) -> 次數(int)

    while (n--) {
        string country, name;
        cin >> country;      // 讀入第一個字：國家名
        getline(cin, name);  // 讀入剩下的部分：名字（讀完但不處理，直接丟掉）

        counts[country]++;   // 核心魔法：國家次數直接 +1
    }

    // 印出結果：map 會自動按國家 A-Z 幫你排好
    for (auto const& [country, count] : counts) {
        cout << country << " " << count << endl;
    }

    return 0;
}