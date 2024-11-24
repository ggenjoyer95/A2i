#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void isrt(vector<int>& a, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        int k = a[i];
        int j = i - 1;
        while (j >= l && a[j] > k) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = k;
    }
}

void mrg(vector<int>& a, int l, int m, int r) {
    vector<int> t(r - l + 1);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= m) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    copy(t.begin(), t.end(), a.begin() + l);
}

void hmsrt(vector<int>& a, int l, int r, int th) {
    if (r - l + 1 <= th) {
        isrt(a, l, r);
    } else {
        int m = l + (r - l) / 2;
        hmsrt(a, l, m, th);
        hmsrt(a, m + 1, r, th);
        mrg(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int th = 15;
    hmsrt(a, 0, n - 1, th);
    for (const int& x : a) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
