#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> st; 
    vector<bool> printed(n + 1, false);

    for (int i = 1; i <= n; i++) {
        char cmd = s[i - 1];
        if (cmd == '1') {
            st.push_back(i);
        } 
        else if (cmd == '2') {
            if (!st.empty()) {
                int doc = st.back();
                st.pop_back();
                printed[doc] = true;
            } else {
                printed[i] = true;
            }
        } 
        else if (cmd == '3') {
            printed[i] = true;
        }
    }

    vector<int> unprinted;
    for (int i = 1; i <= n; i++) {
        if (!printed[i]) {
            unprinted.push_back(i);
        }
    }

    cout << unprinted.size() << "\n";
    for (int i = 0; i < unprinted.size(); i++) {
        cout << unprinted[i] << (i + 1 == unprinted.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}