#include<bits/stdc++.h>
using namespace std;


int countRep(string sub);
string str;

main() {
    int maxi = 0, n;
    string gram;
    cin >> n >> str;

    for (int i = 0; i < str.size() - 1; i++) {
        string sub = str.substr(i, 2); 
        
        int temp = countRep(sub);

        if (temp > maxi) {
            maxi = temp;
            gram = sub;
        }
    }
    cout << gram << endl;
}


int countRep(string sub) {
    int cnt = 0, maxi = 0;

    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == sub[0] && str[i + 1] == sub[1])
            cnt++;
    }
    return cnt;
}