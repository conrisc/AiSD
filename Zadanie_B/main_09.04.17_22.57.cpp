#include <cstdio>

using namespace std;

int main () {

  int n,even,sum=0;
  scanf("%d",&n);
  char line[n][3+1];
  char* neighbour[n][3][4];

  for (int i=0;i<n;i++) {
    fgets (line[i], 2, stdin);
    fgets (line[i], 4, stdin);
  }

  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++) {

    }
  }

  //1****************
  even = 0;
  for (int i=0;i<n;i++) {
    if((i+even)%2==0) {
      if(line[i][0]=='.') {line[i][0]='S'; sum++;}
      else even++;
    }
  }


  //2*******************

  even = 0;
  for (int i=0;i<n;i++) {
    if((i+even)%2==0) {
      if(line[i][2]=='.' &&
        (i-1<0 || line[i-1][0]!='S') &&
        (i+1>=n || line[i+1][0]!='S')
      ) {line[i][2]='S'; sum++;}
      else even++;
    }
  }

  //3******************
  even = 0;
  for (int i=0;i<n;i++) {
    if((i+even)%2==0) {
      if(line[i][1]=='.' &&
        (i-2<0 || line[i-2][0]!='S') &&
        (i+2>=n || line[i+2][0]!='S') &&
        (i-2<0 || line[i-2][2]!='S') &&
        (i+2>=n || line[i+2][2]!='S')
      ) {line[i][1]='S'; sum++;}
      else even++;
    }
  }

  //LAST*****************************************

  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++) {
      if(line[i][j]=='.' &&
        (i-1<0 || j-2<0 || line[i-1][j-2]!='S') &&
        (i+1>=n || j-2<0 || line[i+1][j-2]!='S') &&
        (i-2<0 || j-1<0 || line[i-2][j-1]!='S') &&
        (i+2>=n || j-1<0 || line[i+2][j-1]!='S') &&
        (i-2<0 || j+1>2 || line[i-2][j+1]!='S') &&
        (i+2>=n || j+1>2 || line[i+2][j+1]!='S') &&
        (i-1<0 || j+2>2 || line[i-1][j+2]!='S') &&
        (i+1>=n || j+2>2 || line[i+1][j+2]!='S')
      ) {line[i][j]='S'; sum++;}
    }
  }


  //PRINT CHEESBOARD*******************************
  printf("%d\n",sum);
  for (int i=0;i<n;i++) {
    for (int j=0;j<3;j++){
      printf("%c",line[i][j]);
    }
    printf("\n");
  }

  return 0;
}
