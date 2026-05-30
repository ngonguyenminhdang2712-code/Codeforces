#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long n; cin >> n;
        vector<long long>v(n);
        vector<long long>danhdau;
        long long tempK = 0;
        long long maxK = 0;
        long long check = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long Max = v[0];
        for(int i = 0; i < n; i++)
        {
            if(Max > v[i])
            {    

                danhdau.push_back(i);
                tempK = Max - v[i];
                if(maxK < tempK)
                {
                    maxK = tempK;
                }
            }
            if(Max < v[i])
            {
                Max = v[i];
            }
        }
        



        for(int i = 0; i < danhdau.size(); i++)
        {
            
            v[danhdau[i]] += maxK;

        }
        long long realMax = *max_element(v.begin(), v.end());
        for(int i = danhdau[danhdau.size()-1]; i < n;i++){
            if(realMax > v[i]){
                danhdau.push_back(i);
            }
        }
        for(int i = danhdau[danhdau.size()-1]; i < n;i++)
        {
            
            v[danhdau[i]] += maxK;

        }

        for(int i = 0; i < v.size()-1;i++)
        {
            if(v[i] > v[i+1])
            {
                check = 1;
                break;
            }
        }
        if(check == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";

    }
    
    return 0;
}