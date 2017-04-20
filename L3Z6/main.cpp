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
  int a=0,b=n,sr;
  bool change = true;
  //1
  while (change && mediana<minn) {
    sr = (a+b)/2;
    if (sr==a) change = false;
    int mniej = mniejszych(0,tab[0][sr],n) + mniejszych(1,tab[0][sr],n) + mniejszych(2,tab[0][sr],n);
    int rowny= rownych(0,tab[0][sr],n) + rownych(1,tab[0][sr],n) + rownych(2,tab[0][sr],n);
    int wieks = wiekszych(0,tab[0][sr],n) + wiekszych(1,tab[0][sr],n) + wiekszych(2,tab[0][sr],n);
    // printf("%d\n%d | %d | %d\n\n",tab[0][sr],mniej,rowny,wieks);
    if (mniej<=((3*n)+1)/2-1 && mniej+rowny>=((3*n)+1)/2) mediana = tab[0][sr];
    else if (mniej>wieks) {b=sr;maxx=tab[0][sr];}
    else {a=sr;minn=tab[0][sr];}
  }

  //2
  a=0,b=n;
  change = true;
  while (change && mediana<minn) {
    sr = (a+b)/2;
    if (sr==a) change = false;
    if (tab[1][sr]<=minn) a=sr;
    else if (tab[1][sr]>=maxx) b=sr;
    else {
      int mniej = mniejszych(0,tab[1][sr],n) + mniejszych(1,tab[1][sr],n) + mniejszych(2,tab[1][sr],n);
      int rowny = rownych(0,tab[1][sr],n) + rownych(1,tab[1][sr],n) + rownych(2,tab[1][sr],n);
      int wieks = wiekszych(0,tab[1][sr],n) + wiekszych(1,tab[1][sr],n) + wiekszych(2,tab[1][sr],n);
      // printf("%d\n%d | %d | %d\n\n",tab[1][sr],mniej,rowny,wieks);
      if (mniej<=((3*n)+1)/2-1  && mniej+rowny>=((3*n)+1)/2) mediana = tab[1][sr];
      else if(mniej>wieks) {b=sr;maxx=tab[1][sr];}
      else {a=sr;minn=tab[1][sr];}
    }
  }

  //3
  a=0,b=n;
  change = true;
  while (change && mediana<minn) {
    sr = (a+b)/2;
    if (sr==a) change = false;
    if (tab[2][sr]<=minn) a=sr;
    else if (tab[2][sr]>=maxx) b=sr;
    else {
      int mniej = mniejszych(0,tab[2][sr],n) + mniejszych(1,tab[2][sr],n) + mniejszych(2,tab[2][sr],n);
      int rowny = rownych(0,tab[2][sr],n) + rownych(1,tab[2][sr],n) + rownych(2,tab[2][sr],n);
      int wieks = wiekszych(0,tab[2][sr],n) + wiekszych(1,tab[2][sr],n) + wiekszych(2,tab[2][sr],n);
      // printf("%d\n%d | %d | %d\n\n",tab[2][sr],mniej,rowny,wieks);
      if (mniej<=((3*n)+1)/2-1  && mniej+rowny>=((3*n)+1)/2) mediana = tab[2][sr];
      else if (mniej>wieks) {b=sr;maxx=tab[2][sr];}
      else {a=sr;minn=tab[2][sr];}
    }
  }

  printf("MEDIANA: %d\n", mediana);

  return 0;
}
