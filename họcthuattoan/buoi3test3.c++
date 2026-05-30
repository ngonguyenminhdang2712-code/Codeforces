#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    int q; cin >> q;
    vector <long long> docao(n);
    while(q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        docao[l]+= x;
        docao[r-1] -= x;
    }
    long long sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        sum += docao[i];
        cout << v[i] + sum << " ";
    }
}