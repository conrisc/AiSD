#include <cstdio>
#include <algorithm>

int tab[3][1000000],n,minn,maxx,mediana;

int mniejszych(int i,int x, int n) {
  int res = 0;
  for (;res<n && tab[i][res]<x;res++) {}
  return res;
}

int rownych(int i,int x, int n) {
  int res = 0;
  for (int j=0;j<n;j++) {if(tab[i][j]==x) res++;}
  return res;
}

int wiekszych(int i,int x, int n) {
  int res = 0;
  for (;res<n && tab[i][res]<=x;res++) {}
  return n-res;
}

using namespace std;

int main() {

  scanf("%d",&n);

  for (int i=0;i<3;i++) {
    for (int j=0;j<n;j++) {
      scanf("%d",&tab[i][j]);
    }
  }
  minn = tab[0][0];
  for (int i=1;i<3;i++) minn = min(minn,tab[i][0]);
  maxx = tab[0][n-1];
  for (int i=1;i<3;i++) maxx = max(maxx,tab[i][n-1]);
  mediana = minn-1;

  ///main
  int a,b,sr;
  bool change;
  for (int i=0;i<3;i++) {
    a=0,b=n;
    change = true;
    while (change && mediana<minn) {
      sr = (a+b)/2;
      if (sr==a) change = false;
      if (tab[i][sr]<=minn) a=sr;
      else if (tab[i][sr]>=maxx) b=sr;
      else {
        int mniej = mniejszych(0,tab[i][sr],n) + mniejszych(1,tab[i][sr],n) + mniejszych(2,tab[i][sr],n);
        int rowny = rownych(0,tab[i][sr],n) + rownych(1,tab[i][sr],n) + rownych(2,tab[i][sr],n);
        int wieks = wiekszych(0,tab[i][sr],n) + wiekszych(1,tab[i][sr],n) + wiekszych(2,tab[i][sr],n);
        if (mniej<=((3*n)+1)/2-1  && mniej+rowny>=((3*n)+1)/2) mediana = tab[i][sr];
        else if(mniej>wieks) {b=sr;maxx=tab[i][sr];}
        else {a=sr;minn=tab[i][sr];}
      }
    }
  }

  printf("MEDIANA: %d\n", mediana);

  return 0;
}
