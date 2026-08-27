#include <bits/stdc++.h>

using namespace.std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    while(cin >> a >> b){

        if(a == 0 && b == 0) return 0;

        // Calculation
        int count = 0, carry = 0;

        while(a || b){    //當a或b有一數等於0便停止計算
            if(a%10 + b%10 + carry >= 10) {
                count++;
                carry=1;
            } else {
                carry=0;
            }
            a /= 10;
            b /= 10;
        }

        // Output
        if(count == 0) cout << "No carry operation.\n";
        else if(count == 1) cout << "1 carry operation.\n";
        else cout << count << " carry operations.\n";

    }

    return 0;

}