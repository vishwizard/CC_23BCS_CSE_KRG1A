#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<string> & words){
    int n = words.size();
    vector<int> mp(n,0);
    for(int i = 0; i<n; i++){
        for(char &ch : words[i]) mp[i] |= (1 << (ch-'a'));
    }
    int maxi = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){

            if((mp[i]&mp[j]) == 0) {
                int a = words[i].length();
                int b = words[j].length();
                maxi = max(maxi, a*b);
            }
        }
    }
    return maxi;
}
int main(){
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i<n; i++){
        cin >> words[i];
    }
    cout << maxLen(words);
    return 0;
}
