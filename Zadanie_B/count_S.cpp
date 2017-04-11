#include <cstdio>

using namespace std;

char line[1000000][4];

int main () {

  int n,result=0;
  scanf("%d",&n);

  for (int i=0;i<1000;i++) {
    fgets (line[i], 2, stdin);
    fgets (line[i], 4, stdin);
  }

  for (int i=0;i<1000;i++) {
    for (int j=0;j<3;j++) {
      if (line[i][j]=='S') result++;
    }
  }
  //PRINT CHEESBOARD*******************************
  printf("%d\n",result);

  return 0;
}
