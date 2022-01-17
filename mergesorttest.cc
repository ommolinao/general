#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& v, vector<int>& left, vector<int>& right) {
    int i = 0;
    int j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            v[i + j] = left[i];
            i++;
        } else {
            v[i + j] = right[j];
            j++;
        }
    }
    while (i < left.size()) {
        v[i + j] = left[i];
        i++;
    }
    while (j < right.size()) {
        v[i + j] = right[j];
        j++;
    }
}

void mergeSort(vector<int>& v) {
    if (v.size() == 1) return;
    else
    if (v.size() == 2) {
        if (v[0] > v[1]) swap(v[0], v[1]);
        return;
    }
    int mid = v.size() / 2;
    vector<int> left = vector<int>(v.begin(), v.begin() + mid);
    vector<int> right = vector<int>(v.begin() + mid, v.end());
    mergeSort(left);
    mergeSort(right);
    merge(v, left, right);
}

int main(int argc, char const *argv[]) {
    int n;
    cout << "Number of elements: ";
    cin >> n;
    cout << "Insert elements: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    mergeSort(v);
    cout << "Sorted array: ";
    for (const auto & e : v) cout << e << " ";
    cout << '\n';
}
