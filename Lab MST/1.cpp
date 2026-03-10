#include <bits/stdc++.h>
using namespace std;

long long init(vector<vector<int>> & tasks){
    int n = tasks.size();
    long long sum = 0;
    for(int i = 0; i<n; i++){
        sum += tasks[i][0];
    }
    sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b){
        int d1 = a[1] - a[0];
        int d2 = b[1] - b[0];
        if(d1 == d2) return a[1] > b[1];
        return d1 > d2;
    });
    long long temp = sum;
    for(int i = 0; i<n; i++){
        if(temp < tasks[i][1]){
            int diff = tasks[i][1] - temp;
            temp += diff;
            sum += diff;
        }
        temp -= tasks[i][0];
    }
    return sum;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> tasks(n, vector<int>(2,0));
    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        tasks[i][0] = a;
        tasks[i][1] = b;
    }
    cout << init(tasks);
    return 0;
}
