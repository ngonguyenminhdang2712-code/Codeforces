/*long long findMEX(vector<long long>& a) {
    long long n = a.size();
    vector<bool> present(n + 1, false);

    for (long long x : a) {
        if (x >= 0 && x < n) {
            present[x] = true;
        }
    }

    for (long long i = 0; i <= n; i++) {
        if (present[i] == false) return i;
    }
    return n;
}
    */