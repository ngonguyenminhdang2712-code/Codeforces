/*
Jen là 1 người nghiện xem TV, anh ấy có đến 2 chiếc TV để có thể xem nhiều chương trình hơn cùng 1 lúc.
Ngày hôm nay, có n chương trình ưa thích mà Jen muốn xem. Chương trình thứ i bắt đầu lúc li và kết thúc lúc ri. 
Lưu ý rằng tại 1 thời điểm, 1 TV chỉ có thể mở 1 chương trình. 
Ví dụ, nếu 1 TV đang mở chương trình thứ i thì phải đến thời điểm ri + 1 TV đó mới rảnh và có thể chuyển sang chương trình ưa thích tiếp theo.

Hãy giúp Jen tính toán xem anh ấy có thể xem hết tất cả chương trình ưa thích của mình không?

Input:

Dòng đầu tiên chứa số nguyên n (1 ≤ n ≤ 2 * 10^5) — Số lượng chương trình ưa thích.

n dòng tiếp theo, mỗi dòng chứa 2 số nguyên li, ri — Thời gian bắt đầu và thời gian kết thúc của chương trình thứ i (0 ≤ li ≤ ri ≤ 10^9).

Output:

Nếu Jen có thể xem hết các chương trình ưa thích thì in ra "YES", nếu không in ra "NO".
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>>show;
    for(int i = 0; i<n; i++)
    {
        long long l, r;
        cin >> l >> r;

        show.push_back({l,1});
        show.push_back({r+1,-1});
    }
    sort(show.begin(),show.end());
    int cur = 0; // số đoạn đang hoạt động tại thời điện hiện tại
    for (int i = 0; i < show.size(); i++)
    {
        cur += show[i].second;
        if(cur > 2)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}