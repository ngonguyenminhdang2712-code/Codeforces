//bai1 contest dau vao
/*
Bạn được cho một dãy số 
𝐴
A gồm n số nguyên không âm và thuật toán Binh Duong như sau:

Bạn được phép sử dụng thao tác sau đây với số lần bất kì:

Chọn 1 chỉ số i bất kì, thay thế 
𝑎i = ai * ai


Hãy xác định xem bằng thuật toán đọc lại trên có thể biến dãy thành dãy không giảm không?

Input

Dòng đầu gồm 
𝑇
T là số lượng test. Mỗi test gồm 2 dòng:

Dòng thứ nhất là số n, độ dài dãy số 𝐴

Dòng thứ hai là n số nguyên không âm a1,a2,...an

Tổng các số n <= 10 mũ 6 

Output

Mỗi test in ra "YES" nếu có thể hoặc "NO" nếu không thể.
Mỗi test cách nhau một dấu xuống dòng.

Example

input

2
2
3 6
4
196 2 5 0

output

YES
NO

*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) // giống với T > 0 thôi
    {
        int n;
        cin >> n;
        vector <long long > a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool ok = true;
        for(int i = 1; i < n; i++)
        {
            if(a[i] >= a[i-1])
            {
                continue;
            }
            if( a[i] == 1 && a[i-1] > 1)
            {
                ok = false;
                break;
            }
            while (a[i] < a[i-1])
            {
                a[i] = a[i] * a[i];
            
            }
            if( a[i] < a[i-1])
                {
                    ok = false;
                    break;
                }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

}