/*
Per đang có 1 xâu ký tự S độ dài N. Nếu số K gọi là may mắn với xâu đã cho thì các xâu con độ dài K của xâu S là phải phân biệt với nhau.
Bạn hãy giúp Per tìm ra số may mắn nhỏ nhất của xâu đã cho nhé! Lưu ý rằng xâu con ở đây là các ký tự liên tiếp nhau.

Input
Gồm 2 dòng:

Dòng đầu tiên chứa số N (1 ≤ N ≤ 100), độ dài của xâu ký tự.

Dòng thứ hai chứa xâu ký tự S.

Output
In ra đáp án là số may mắn nhỏ nhất của xâu.
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{   ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    map <string,int> mp;
    for(int k = 1; k <= N; k++)
    {
        bool ok = true;
        for(int i = 0; i + k <= N; i++) 
                                        // chuỗi có độ dại là N thì lấy chuỗi hợp lệ điều kiện sẽ là 0 -> N-1
                                        // vì khi lấy xâu ở vị trí i theo k kí tự thì để lấy xâu cuối hợp lệ thì..
                                        // xâu cuối sẽ ở vị trí i + k - 1 => i + k - 1 <= N - 1
        {
            string sub = S.substr(i,k); // lấy xâu kí tự
            mp[sub]++; 
            if (mp[sub] > 1)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << k;
            return 0;
        }
    }


}


