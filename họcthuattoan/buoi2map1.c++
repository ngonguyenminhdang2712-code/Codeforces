/*
Per duoc cho 1 mang A do dai N va so nguyen X.
Cau muon xac dinh xem co ton tai hai vi tri i va j sao cho:
A[i] + A[j] = X
1 <= i, j <= N, i != j
Vi se co the ton tai rat nhieu cap i, j nen ban hay giup Per tim cap so nho nhat nhe.
Input

Test gom 2 dong:
Dong dau tien chua so N (1 <= N <= 2 * 10^5) va so X (1 <= X <= 10^9)
Dong thu hai chua mang A (1 <= A[i] <= 10^9)

Output
In ra hai vi tri nho nhat thoa man de bai tren cung mot dong. Neu khong ton tai cap vi tri nao thi in ra "HETCUU".

Example

Input
1 2
1

Output
HETCUU
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,x;
    cin >> N >> x;
    vector <long long> A(N);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    map <long long, long long> mp;
    for(int i = 0; i < N; i++)
    {
      long long j = x - A[i];
      if(mp.count(j))
      {
        cout << mp[j] << " " << i+1;
        return 0;
      }
      if(!mp.count(A[i]))
      {
        mp[A[i]] = i + 1;
      }
    }
    cout <<"HETCUU";
    

}