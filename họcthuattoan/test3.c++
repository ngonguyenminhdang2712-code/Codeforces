#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct {
    double c; //coefficients
    int e;    //exponents
} ElementType;

typedef vector<ElementType> Polynomial;      

void printPolynomial(Polynomial *pL) {       
    if (pL->size() == 0)
        return;

    cout << std::fixed << setprecision(2);
    cout << '(' << (*pL)[0].c << ")x^" << (*pL)[0].e;
        
    for (int i = 1; i < pL->size(); i++)
        cout << setprecision(2) << " + " << '(' << (*pL)[i].c << ")x^" << (*pL)[i].e;
    
    cout << endl;
}

void insert(double c, int e, Polynomial *pL)
{
  for (auto it = pL->begin(); it != pL->end(); it++) {
        if (it->e == e) {
            it->c = c;
            return;
        }
        if(it->e < e)
        {
            ElementType them = {c, e};
            pL->insert(it,them);
            return;
        }
    }
    pL->push_back({c, e});
}

void delete_e(int e, Polynomial *pL)
{
  bool check = true;
  for(auto it = pL->begin(); it != pL->end(); it++)
  {
    if(it->e == e)
    {
      pL->erase(it);
      check = false;
      break;
    }
  }
  if(check == true) cout << "The exponent does not appear.\n";
}

Polynomial differentiate(Polynomial *pL)
{
  vector<ElementType>result;
  for(auto it = pL->begin(); it != pL->end(); it++)
  {
    if(it->e != 0)
    {
      double cmoi = it->c * it->e;
      int emoi = it->e - 1;
      result.push_back({cmoi,emoi});
    }
  }
  return result;
}

double evaluate(double val, Polynomial *pL)
  {
    double sum =0.0;
    for(auto it = pL->begin(); it != pL->end(); it++)
    {
      sum += pow(val,it->e) * it->c;
    }
    return sum;
  }

double coefficient(int e, Polynomial *pL)
{

  for(auto it = pL->begin(); it != pL->end(); it++)
    {
      if(it->e == e)
      {
      
        return it->c;
        
      }
    } 
    return 0.0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}