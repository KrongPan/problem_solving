#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

array<pair<pair<int,int>,short>,100001> dna;//firstF secondB
int l, n;
void print_dna();
int main() {
  cin >> l >> n; 
  int in;
  int s = 1;
  for(int i = 0; i < l; i++)
  {
    cin >> in;
    for(int j = s; j <= in; j++)
    {
      if(j==s)
      {
        dna[s].first.first = j+1;
        dna[s].first.second = 0;
        dna[s].second = 1;
      }
      else if(j == in)
      {
        dna[in].first.first = 0;
        dna[in].first.second = j-1;
      }
      else
      {
        dna[j].first.first = j+1;
        dna[j].first.second = j-1;
      }
    }
    s = in+1;
  }
  char c;
  int it = 1;
  bool dir = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> c;
    if (c == 'B' && it > 1)
    {
      it--;
    }
    else if(c == 'F' && it < in)
    {
      it++;
    }
    else if(c == 'C')
    {
      int cut;
      cin >> cut;
      
      if(dna[cut].first.first == 0)
      {
        dna[cut].second = 2;
        dir = 1;
      }
      else
      {
        if(dir)
        {
          dna[cut].second = 1;
        }
        dir = 0;
        dna[cut].first.second = it;
      }
      dna[dna[it].first.first].first.second = 0;
      dna[it].first.first = cut;
      it = cut;      
    }
    print_dna();
  }
  
}

void print_dna()
{
  int it = 1;
  bool dir = 0;
  while(true)
  {
    Sleep(300);
    
    if((!dir && dna[it].first.first == 0) || (dir && dna[it].first.second == 0))
    {
      break;
    }
    cout << it << ' ';
    if(!dir)
    {
      
      it = dna[it].first.first;
    }
    else if(dir)
    {
      
      it = dna[it].first.second;
    }
    if(dna[it].second == 2)
      {
        dir = 1;
      }
    else if(dna[it].second == 1)
      {
        dir = 0;
      }
  }
  cout << '\n';
}