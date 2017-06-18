#include <cstdio>
#include <algorithm>

using namespace std;

struct Edge {
  int a,b;
};

bool comparator(Edge x,Edge y) {
  return (x.a<y.a) || (x.a==y.a && x.b<y.b);
}

int main() {

  int d,n,a,b;

  scanf("%d",&d);
  for (int z=0;z<d;z++) {
    scanf("%d",&n);
    Edge tab[n*2-2];
    for (int i=0;i<2*n-2;i++) {
      scanf("%d %d",&a,&b);
      if (a<b) {
        tab[i].a = a;
        tab[i].b = b;
      }
      else {
        tab[i].a = b;
        tab[i].b = a;
      }
    }
    sort(tab,tab+n*2-2,comparator);
    printf("WYPISZ:\n");
    for (int i=0;i<2*n-2;i++)
      printf("%d %d\n",tab[i].a,tab[i].b);
    printf("\n");
  }




  return 0;
}
