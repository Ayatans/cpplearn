#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
using namespace std;


// No.1 100
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n, m;
//        cin >> n >> m;
//        vector<string> p;
//        for (int i = 0; i < n; ++i) {
//            string s;
//            cin >> s;
//            p.push_back(s);
//        }
//        vector<string> ans;
//        int meihangchongfu = ((m - n) / 2) / n;
//        int banbian = ((m - n) / 2) % n;
//        vector<string> changedp;
//        for (int i = 0; i < n; ++i) {
//            string tmp = p[i];
//            for (int j = 0; j < meihangchongfu; ++j) {
//                tmp = p[i] + tmp + p[i];
//            }
//            tmp = p[i].substr(n - banbian, n) + tmp + p[i].substr(0, banbian);
//            changedp.push_back(tmp);
//        }
//        for (int i = 0; i < 2 * meihangchongfu + 1; ++i) {
//            for (int j = 0; j < n; ++j) {
//                ans.push_back(changedp[j]);
//            }
//        }
//        for (int i = n - 1; i > n - banbian - 1; --i) {
//            ans.insert(ans.begin(), changedp[i]);
//        }
//        for (int i = 0; i < banbian; ++i) {
//            ans.push_back(changedp[i]);
//        }
//        for (int k = 0; k < ans.size(); ++k) {
//            cout << ans[k] << endl;
//        }
//        cout << endl;
//    }
//}



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        vector<vector<int>> nums(n, vector<int>(4));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> nums[i][j];
            }
        }
        vector<int> used;
        for (int i = 0; i < n - 1; ++i) {
            vector<int>::iterator iinused;
            iinused = find(used.begin(), used.end(), i);
            if (iinused != used.end()) {
                continue;
            }
            int x0i = nums[i][0];
            int y0i = nums[i][1];
            int x1i = nums[i][2];
            int y1i = nums[i][3];
            for (int j = i + 1; j < n; ++j) {
                vector<int>::iterator jinused;
                jinused = find(used.begin(), used.end(), j);
                if (jinused != used.end()) {
                    continue;
                }
                cout << i << ' ' << j << endl;
                int x0j = nums[j][0];
                int y0j = nums[j][1];
                int x1j = nums[j][2];
                int y1j = nums[j][3];
                if (((x0i > x0j) && (y0i > y0j) && (x1i < x1j) && (y1i < y1j)) || ((x0i < x0j) && (y0i < y0j) && (x1i > x1j) && (y1i > y1j))) {
                    continue;
                }
                int xjiao1 = max(x0i, x0j);
                int yjiao1 = max(y0i, y0j);
                int xjiao2 = min(x1i, x1j);
                int yjiao2 = min(y1i, y1j);
                int wjiao = max(0, xjiao2 - xjiao1);
                int hjiao = max(0, yjiao2 - yjiao1);
                int intersec = wjiao * hjiao;
                if (intersec == 0) {
                    continue;
                }
                int si = (x1i - x0i) * (y1i - y0i);
                int sj = (x1j - x0j) * (y1j - y0j);
                //cout << intersec <<si <<sj<<endl;
                used.push_back(i);
                used.push_back(j);
                ans = ans + si + sj - intersec;
                break;
            }
        }
        cout << ans << endl;
    }
}