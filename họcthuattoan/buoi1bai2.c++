#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Anh Rô được cho 1 số nguyên N.

Anh muốn xác định xem có tồn tại dãy Siiuuu không? 
Dãy Siiuuu là dãy các số nguyên dương a1, a2, ..., ak (không nhất thiết phải phân biệt) 
được tách từ N sao cho:

- ai ≥ 1, k ≥ 2
- a1 + a2 + ... + ak = N
- LCM(a1, a2, ..., ak) = N

Cho các bạn chưa biết thì LCM (Least Common Multiple) chính là bội chung nhỏ nhất.

Input:
Dòng đầu gồm T là số lượng test (1 ≤ T ≤ 100).
Mỗi test gồm 1 dòng duy nhất chứa số N (2 ≤ N ≤ 10^9).

Output:
Mỗi test in ra "YES" nếu tồn tại dãy Siiuuu hoặc "NO" nếu không.
Mỗi test cách nhau một dấu xuống dòng.

Example:

Input:
2
2
10

Output:
NO
YES

Note:
Với test thứ 2, ta có thể tách 10 = 1 + 2 + 2 + 5.
*/
// tư duy bài toán: vì LCM(N,1) = N suy ra ta cần làm thế nào đó để chèn số 1 vào a1 + a2 + ... + ak = N mới ko làm thay đổi lcm
// có thể làm bằng cách phân tích thành các thừa số nguyên tố của N với điều kiện là N phải có >=2 tsnt
/*
1) Phân tích N ra prime factor.
2) Nếu chỉ có 1 prime → -1.
3) Nếu ≥ 2 prime:
   - Lấy một prime power làm a1.
   - a2 = N / a1.
   - Thêm số 1 để đủ tổng.*/
// code ở dưới đây là  code nâng cao hơn đề bài cho rồi vì in ra đủ các phần tử còn đề bài thì chỉ cần phân tích ra thừa số nt à dc
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        long long temp = N;
        vector<pair<long long, long long >> factor;
        for( long long i = 2; i * i <= temp; i++)
        {
            if ( temp % i == 0) // dùng để đếm xem số ngto do co bao nhiêu số mũ ví dụ 2^2
            {
                long long count = 0;
                while(temp % i == 0)
                {
                    temp = temp / i;
                    count++;
                }
                factor.push_back({i,count});
            }
        }
        if ( temp > 1)
        {
            factor.push_back({temp,1}); // sao khi chạy vòng for temp / i thì còn lại số ngto cuối cùng rồi xét nó
        }
        if(factor.size() == 1)
        {
            cout << -1 << "\n";
            continue;
        }
        long long a1 = 1;
        for(int i = 0; i < factor[0].second; i++)
        {
            a1 *= factor[0].first;
        }
        long long a2 = N / a1;
        vector<long long> dapan;
        dapan.push_back(a1);
        dapan.push_back(a2);
        long long sum = a1 + a2;
        while (sum < N)
        {
            dapan.push_back(1); //cộng 1 vào cho đủ N
            sum++;
        }
        cout <<dapan.size() << "\n";
        for(int i = 0; i <= dapan.size(); i++)
        {
            cout << dapan[i];
        } 
    }

    
}