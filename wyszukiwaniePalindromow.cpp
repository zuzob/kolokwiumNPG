// Wyszukiwanie palindrom�w
// Data: 9.08.2008
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 40; // d�ugo�� �a�cucha s

int main()
{
  string s;
  int i,j,k,iP,iL;
  bool t;

// generujemy �a�cuch s

  srand((unsigned)time(NULL));
  s = "";
  for(i = 0; i < N; i++) s += char(65 + rand() % 4);

// wypisujemy �a�cuch s

  cout << s << endl;

// szukamy palindrom�w

  for(i = 0; i < N - 1; i++)
    for(j = i + 2; j <= N; j++)
    {
      iL = i; iP = j - 1; t = true;
      while(iL < iP)
        if(s[iL++] != s[iP--])
        {
          t = false; break;
        }
      if(t)
      {
        for(k = 0; k < i; k++) cout << " ";
        cout << s.substr(i,j-i) << endl;
      }
    }
  cout << endl;
  return 0;
} 