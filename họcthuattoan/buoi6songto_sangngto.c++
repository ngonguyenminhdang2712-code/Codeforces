#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// duyệt các số nguyên tố từ 1 - n theo sàng nguyên tố dùng trong CF;
#define maxN 10000
int d[maxN];
int main()
{
    int n; cin >> n;
    d[0] = d[1] = 1;
    for(int i = 2; i < n; i++)
    {
        if(d[i] == 0) /// có nghĩa là ví dụ số 2 là số nguyên tố thì nó đánh dấu là 0 và các số (bội) thì ko phải là số nguyên tố 
        // nên đánh dấu là 1;
        {
            for(int j = i * i; j < n; j+=i)
            {
                d[j] = 1;
            }
        }
    }
}

///////////TÍNH TỔNG ƯỚC CỦA 1 SỐ TỪ 1-N THEO SÀNG NGTO
int sum[maxN];
int main()
{
    int n; cin >> n;
    for(int i = 1; i <=n; i++) 
    {
        for(int j = i; j <=n; j += i)
        {
            sum[j] += i;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << "Tong uoc cua " << i << " = " << sum[i] << endl;
    }
}
/////////////LIỆT KÊ CÁC THỪA SỐ NGUYÊN TỐ CỦA N////////////
int main()
{
    int n; cin >> n;
    for(int i = 2; i * i <= n; i++)
    {
        while(n%i == 0)
        {   
            cout << i << " ";
            n = n / i;
        }
    }
    if ( n > 1) cout << n;
}
///////////////ĐẾM CÁC ƯỚC CỦA N////////////////
// CÁCH 1:
int main()
{
    int n; cin >> n;
    int count = 0;
    for(int i = 1; i * i <= n; i++)
    { if (n% i == 0)
       { if(i != n / i)
        {
            count += 2;
        }
        if(i == n / i) count += 1;
        }
    }
    cout << count;
}
// CÁCH 2
int main()
{
    int n; cin >> n;
    int ans = 0;
    int count = 0;
    for(int i = 2; i * i <=n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0) //ví dụ n = 10 có 4 ước là 1 10 2 5, thì ta có thừa số nguyên tố của 10 là 2 mũ 1 * 5 mũ 1
                              // thì ta lấy số mũ của 2 + 1 nhân với số mũ của 5 + 1 tức ( 1 + 1 * 1 + 1) = 4
                              // nên hướng làm bài này ta sẽ phân tích thành thừa số nguyên tố trước rồi với mỗi thừa số 
                              // ta đem nhân với count + 1; 
            {
                n = n/i;
                count++;
            }
            ans *= count + 1;
        }
    }
    if(n > 1) ans *= 2;
}

///CÁCH 3 SÀI SÀNG NGUYÊN TỐ ĐẾM SỐ ƯỚC N
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j+=i)
        {
            d[j]++;
        }
    }
    cout << d[n];
}

///////////////ĐẾM SỐ NGUYÊN TỐ TRONG ĐOẠN L-R, ĐIỀU KIỆN: R-L+1 <= 10 MŨ 6
///// NOTE*: nếu như làm theo cách thông thường khi kiểm tra nguyên tố i * i <= n thì có thể lên tới 10 mũ 12
/// nên sẽ bị TLE. Cách làm là phải duyệt sàng nguyên tố

int main()
{
    long long l, r; cin >> l >> r;
    for(int i = 2; i <= 1e6; i++)
    {
        long long j  = (l+i-1)/i*i; ///số đầu tiên chia hết cho i mà lớn hơn = L (bội đầu tiên của i >= L)
        for(j; j <= r; j += i)
        {
            if(j != i) /// nếu l = 2 mà i cũng = 2 thì j sẽ = 2 mà j là số nguyên tố nên ko đánh dấu = 1
            {
                d[j-l] = 1;   
            }
        }
    }
    for(int i = 0; i <= r - l; i++)
    {
        if(d[i] == 0)
        {
            cout << i + l << " ";
        }
    }
}

////////////////////CẶP SỐ CÓ ƯỚC CHUNG LỚN NHẤT////////////////////
int d[maxN];
int c[maxN];
int main()
{
    int n; cin >> n;
    for(int i = 1; i <=n; i++)
    {
        int x; cin >> x;
        d[x]++; /// đếm số lần xuất hiện của x;
    }
    for(int i = 1; i < maxN;i++)
    {
        for(int j = i; j < maxN; j+=i)
        {
            c[i] += d[j]; 
        }
    }
    for(int i = maxN-1;;i--)
    {
        if(c[i] >= 2)
        {
            cout << i; 
            return 0;
        }
    }
}
//////////////TỔNG SỐ ƯỚC CỦA ĐOẠN L-R////////////////
int d[maxN];
int main()
{
    for(int i = 1; i < maxN; i++)
    {
        for(int j = i; j < maxN; j+=i)
        {
            d[j]++;
        }
        d[i] += d[i-1];//tổng số ước từ 1 - i;
    }
    int t; cin >> t;
    while(t--)
    {
        int l, r; cin >> l >> r;
        cout << d[r]-d[l-1] << '\n';
    }
}
