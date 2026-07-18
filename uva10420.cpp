#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector<string> countries;

    for(int i=0;i<n;i++){
        string country, name;
        cin>>country;
        getline(cin, name);

        countries.push_back(country);
    }

    sort(countries.begin(),countries.end());

    for (int i = 0; i < countries.size(); i++){
        int count = 1;

        while (i + 1 < countries.size() && countries[i] == countries[i + 1]){
            count++;
            i++;
        }

        cout << countries[i] << " " << count << endl;
    }

    return 0;

}