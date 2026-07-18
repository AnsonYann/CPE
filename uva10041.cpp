#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int T;
    cin>>T;

    while(T--){

        int r;
        cin>>r;

        vector <int> s (r);

        for(int i=0;i<r;i++){
            cin>>s[i];
        }

        sort (s.begin(),s.end());

        int median = s[r/2];
        int result = 0;

        for(int i=0;i<r;i++){
            result += abs(median-s[i]);
        }        

        cout<<result<<endl;

    }

    return 0;

}