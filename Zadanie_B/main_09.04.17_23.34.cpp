#include <cstdio>

using namespace std;

int main () {

  int n,result=0;
  scanf("%d",&n);
  char line[n][3+1];
  char* neighbour[n][3][4];

  for (int i=0;i<n;i++) {
    fgets (line[i], 2, stdin);
    fgets (line[i], 4, stdin);
  }

  for (int i=0;i<n;i++) {
    //j==0;
    if (line[i][0] == '.') {
      if (i-2>=0) neighbour[i][0][0]=&line[i-2][1]; else neighbour[i][0][0] = NULL;
      if (i-1>=0) neighbour[i][0][1]=&line[i-1][2]; else neighbour[i][0][1] = NULL;
      if (i+1<n) neighbour[i][0][2]=&line[i+1][2]; else neighbour[i][0][2] = NULL;
      if (i+2<n) neighbour[i][0][3]=&line[i+2][1]; else neighbour[i][0][3] = NULL;
    }
    //j==1;
    if (line[i][1] == '.') {
      if (i-2>=0) neighbour[i][1][0]=&line[i-2][0]; else neighbour[i][1][0] = NULL;
      if (i-2>=0) neighbour[i][1][1]=&line[i-2][2]; else neighbour[i][1][1] = NULL;
      if (i+2<n) neighbour[i][1][2]=&line[i+2][0]; else neighbour[i][1][2] = NULL;
      if (i+2<n) neighbour[i][1][3]=&line[i+2][2]; else neighbour[i][1][3] = NULL;
    }
    //j==2;
    if (line[i][2] == '.') {
      if (i-2>=0) neighbour[i][2][0]=&line[i-2][1]; else neighbour[i][2][0] = NULL;
      if (i-1>=0) neighbour[i][2][1]=&line[i-1][0]; else neighbour[i][2][1] = NULL;
      if (i+1<n) neighbour[i][2][2]=&line[i+1][0]; else neighbour[i][2][2] = NULL;
      if (i+2<n) neighbour[i][2][3]=&line[i+2][1]; else neighbour[i][2][3] = NULL;
    }
  }
  //MAIN*******************************************

  //PRINT CHEESBOARD*******************************
  printf("%d\n",result);
  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++){
      printf("%c",line[i][j]);
    }
    printf("\n");
  }

  return 0;
}
