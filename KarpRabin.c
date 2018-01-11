// Wyszukiwanie wzorca algorytmem KR
// Data:  4.07.2008
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N  = 80;  // d�ugo�� �a�cucha s
const int M  =  4;  // d�ugo�� wzorca p
const int zp = 65;  // kod pierwszego znaku alfabetu
const int zk = 67;  // kod ostatniego znaku alfabetu

// Funkcja obliczaj�ca hasz dla �a�cucha x
//----------------------------------------
int h(string & x)
{
  int i, hx;

  hx = 0;
  for(i = 0; i < M; i++)
    hx = 3 * hx + (x[i] - 65);
  return hx;
}

int main()
{

  string s,p;
  int pp,i,Hp,Hs;

  srand((unsigned)time(NULL));

  // generujemy �a�cuch s

  s = "";
  for(i = 0; i < N; i++)
    s += zp + rand() % (zk - zp + 1);

  // generujemy wzorzec p

  p = "";
  for(i = 0; i < M; i++)
    p += zp + rand() % (zk - zp + 1);

  // wypisujemy wzorzec

  cout << p << endl;

  // wypisujemy �a�cuch

  cout << s;
  
  // obliczamy hasz wzorca

  Hp = h(p);

  // obliczamy hasz okna wzorca

  Hs = h(s);

  // szukamy pozycji wzorca w �a�cuchu

  pp = i = 0;

  while(true)
  {
    if((Hp == Hs) && (p == s.substr(i,M)))
    {
      while(pp < i)
      {
        cout << " "; pp++;
      }
      cout << "^"; pp++;
    }
    i++;
    if(i == N - M) break;
    Hs = (Hs-(s[i-1]-65)*27)*3+s[i+M-1]-65;
  }
  cout << endl;
  return 0;
} 