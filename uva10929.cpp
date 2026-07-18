#include <iostream>
#include <string>

using namespace std;

int main(){

    string str;

    while(cin>>str && str!="0"){

        int odd_sum = 0;
        int even_sum = 0;

        for(int i=0;i<str.length();i++){

            int num = str[i] - '0';

            if(i%2==0){
                even_sum+=num;
            }else{
                odd_sum+=num;
            }

        }

        if((even_sum-odd_sum)%11==0){
            cout<<"y"<<endl;
        }else{
            cout<<"n"<<endl;
        }

    }

}