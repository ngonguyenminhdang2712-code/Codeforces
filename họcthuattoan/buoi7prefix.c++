#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Mảng hiệu : d[i] = a[i] - a[i-1];
//Tổng dồn của mãng hiệu: a[i] = a[i-1] + d[i]; tức là mỗi phần tử a[i] = tổng với a[0] = d[0]; từ d[1]->d[i];
//Mảng tổng : s[i] = s[i-1] + a[i];
//Mảng tổng đoạn l-r: sum = s[r] - s[l-1]; CHÚ Ý: l = 0 thì sum = s[r];
//Tổng dồn 2 chiều: s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]; // tạo mảng s từ a, tổng từ ô 1 1 đến ô i j;
//Tổng 1 vùng bất kỳ 2 chiều: sum = s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1]



//////////////////BÀI 1: TĂNG GIÁ TRỊ CỦA CÁC PHẦN TỬ TỪ L-R LÊN 1 LƯỢNG X///////////////////////// 
int main()
{
    int n, q; cin >> n >> q;
    vector<long long> v(n+2,0); // tạo mãng có n + 2 phần tử và = 0 hết(để tránh truy cập ngoài vùng)
    while(q--)
    {
        int l,r,x; cin >> l >> r >> x;
        v[l] += x;
        v[r+1]-=x;
    }

    vector<long long> a(n);
    a[0] = v[0];

    for(int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + v[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
/////////////////BÀI 2: TĂNG GIÁ TRỊ CỦA CÁC PHẦN TỬ TRONG 1 VÙNG CỦA MẢNg 2 CHIỀU LÊN 1 LƯỢNG X///////////////////////////////
int main()
{
   int n,m,q; cin >> n >> m >> q;
   vector<vector<long long >> d(n+2,vector<long long>(m+2,0)); // mảng 2 chiều n m;
   while(q--)
   {
        int r1, c1, r2, c2, x; cin >> r1 >> c1 >> r2 >> c2 >> x;
        d[r1][c1] += x;
        d[r1][c2+1] -= x;
        d[r2+1][c1] -= x;
        d[r2+1][c2+1] += x;

   }
   vector<vector<long long>> a(n+1, vector<long long>(m+1, 0));
   for(int i = 1; i <= n; i++)
   {
        for(int j = 1; j <= m; j++) 
  //Tổng dồn 2 chiều: s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j]; // tạo mảng s từ a, tổng từ ô 1 1 đến ô i j;
        {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + d[i][j];
        }
   }
   ///cout lười ghi quá
}

///////////////BÀI 3: CHO MẢNG A CÓ N PHẦN TỬ VÀ SỐ NGUYÊN K. TÌM DÃY CÓ ĐỘ DÀI K MÀ TỔNG LỚN NHẤT///////////////
int main()
{
    int n,k; cin >> n >> k;
    vector<long long>a(n+1);
    vector<long long>s(n+1,0);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    long long Max = LLONG_MIN;
    for(int i = k; i <= n; i++)
    {
        long long sum = s[i] - s[i-k];
        Max = max(Max,sum);
    }

   
}
 

///////////////////Bài 4: ĐẾM CÂY///////////////////////
///////// Cho một cái bảng n*n, tính tổng số cây trong cái bảng đó với cây được kí hiệu là "*";
int main()
{
    int n, q; cin >> n >> q;
    vector<vector<char>>d(n+1,vector<char>(n+1));
    vector<vector<int>>s(n+1,vector<int>(n+1));
    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> d[i][j];
            }
        }
         for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(d[i][j] == '*')
                {
                    s[i][j] = 1;
                }
                else s[i][j] = 0;
                s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1]; 
            }
        }
    while(q--)
    {
        int r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int sum = s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
        cout << sum;
    }
}

