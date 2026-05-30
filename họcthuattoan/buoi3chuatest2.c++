#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int q; cin >> q;
    map <int, int> mp;
    while (q--)
    {
        int i; cin >> i;
        int x, a, b;
        if(i == 1)
        {   // chèn a lần xuất hiện vào x
            cin >> x >> a;
            mp[x] += a; //nếu chạy vòng lập từ j - a rồi mp[x] ++ vẫn được nma ko tối ưu

        }
        if(i == 2) // xóa b phần tử x ra khỏi tập hợp trường hợp số lượng ptu x trong tập hợp ko đủ b thì xóa full x
        {
            cin >> x >> b;
            if(mp.count(x))
            {
                mp[x]-=b;
                if(mp[x] <= 0)
                {
                    mp.erase(x);
                }
            }
        }
        if( i == 3)
        {
            int tansuat = 0;
            int giatri = 0;
            for(auto p : mp)
            {
                if(p.second > tansuat)
                {
                    tansuat = p.second;
                    giatri = p.first;
                }
                else if(p.second == tansuat)
                {
                    giatri = max(giatri,p.first);
                }
            }
            cout << giatri << "\n";
        }

    }
}  