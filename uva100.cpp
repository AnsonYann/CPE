#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int i,j;

    while(cin>>i>>j){

        int m = min(i,j);
        int M = max(i,j);
        int max_cycle = 0;

        for (int k=m; k<=M; k++){

            long long n = k;
            int t = 1;

            while(n!=1){
                if (n % 2 != 0)  
                    n = 3 * n + 1;
                else
                    n = n / 2;
                t++;
            }

            max_cycle = max(max_cycle, t);

        }

        cout << i << " " << j << " " << max_cycle << endl;

    }

    return 0;

}