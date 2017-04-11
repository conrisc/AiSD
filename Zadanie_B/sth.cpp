#include <cstdio>

using namespace std;

struct Position {
  int y,x,beats,sum;
};

int main () {

  Position theBest;

  int n,res=0;
  bool exists = true;
  scanf("%d",&n);
  char chessboard[n][4];

  for (int y=0;y<n;y++) {
    fgets (chessboard[y], 2, stdin);
    fgets (chessboard[y], 4, stdin);
  }

  //MAIN*******************************************
  int beats,sum;
  while (exists) {
    exists = false;
    theBest.beats = 5;
    for (int y=0;y<n;y++) {
      for (int x=0;x<n;x++) {
        beats = 0;
        sum = 0;
        if (chessboard[y][x]=='.') {
          exists = true;
          //****************************
          if (y-1>0 && x-2>0 && line[y-1][x-2]=='.') {}
          if (y+1<n && x-2>0 && line[y+1][x-2]=='.')
          if (y-2<0 && x-1>0 && line[y-2][x-1]=='.')
          if (y+2<n && x-1>0 && line[y+2][x-1]=='.')
          if (y-2<0 && x+1<3 && line[y-2][x+1]=='.')
          if (y+2<n && x+1<3 && line[y+2][x+1]=='.')
          if (y-1<0 && x+2<3 && line[y-1][x+2]=='.')
          if (y+1<n && x+2<3 && line[y+1][x+2]=='.')

          //****************************
        }
      }
    }
  }


  //PRINT chessBOARD*******************************
  printf("%d\n",res);
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++){
      printf("%c",chessboard[y][x]);
    }
    printf("\n");
  }

  return 0;
}
