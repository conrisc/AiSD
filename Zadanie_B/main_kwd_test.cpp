#include <cstdio>
#include <algorithm>

using namespace std;

char line[1000000][4];

struct Position {
  int x,y,beats,sum1,sum2;
};

bool sprawdz(Position pos, int sum1, int sum2) {
  if(pos.sum1+pos.sum2<sum1+sum2) return true;
  if(pos.sum1+pos.sum2==sum1+sum2 &&
    sum1>min(pos.sum1,pos.sum2) &&
    sum2>min(pos.sum1,pos.sum2)
  ) return true;

  return false;
}

int howManyPositionsBeats(int y,int x, int n) {
  int result = 0;
  if (y-1>=0 && x-2>=0 && line[y-1][x-2]=='.') {result++;}
  if (y+1<n && x-2>=0 && line[y+1][x-2]=='.') {result++;}
  if (y-2>=0 && x-1>=0 && line[y-2][x-1]=='.') {result++;}
  if (y+2<n && x-1>=0 && line[y+2][x-1]=='.') {result++;}
  if (y-2>=0 && x+1<3 && line[y-2][x+1]=='.') {result++;}
  if (y+2<n && x+1<3 && line[y+2][x+1]=='.') {result++;}
  if (y-1>=0 && x+2<3 && line[y-1][x+2]=='.') {result++;}
  if (y+1<n && x+2<3 && line[y+1][x+2]=='.') {result++;}
  return result;
}

void lock(int y,int x, int n) {
  if (y-1>=0 && x-2>=0 && line[y-1][x-2]=='.') {line[y-1][x-2]='Z';}
  if (y+1<n && x-2>=0 && line[y+1][x-2]=='.') {line[y+1][x-2]='Z';}
  if (y-2>=0 && x-1>=0 && line[y-2][x-1]=='.') {line[y-2][x-1]='Z';}
  if (y+2<n && x-1>=0 && line[y+2][x-1]=='.') {line[y+2][x-1]='Z';}
  if (y-2>=0 && x+1<3 && line[y-2][x+1]=='.') {line[y-2][x+1]='Z';}
  if (y+2<n && x+1<3 && line[y+2][x+1]=='.') {line[y+2][x+1]='Z';}
  if (y-1>=0 && x+2<3 && line[y-1][x+2]=='.') {line[y-1][x+2]='Z';}
  if (y+1<n && x+2<3 && line[y+1][x+2]=='.') {line[y+1][x+2]='Z';}
}

int main () {

  int n,result=0;
  scanf("%d",&n);

  for (int i=0;i<n;i++) {
    fgets (line[i], 2, stdin);
    fgets (line[i], 4, stdin);
  }
  //MAIN*******************************************
  Position theBest;
  bool exists = true, found = false;
  int beats, sum[4],i;
  while (exists) {
    exists = false; found=false;
    theBest.beats = 5; theBest.sum1 = 0; theBest.sum2 = 0;
    for (int y=0;y<n && !found;y++) {
      for (int x=0;x<3 && !found;x++) {
        beats = 0; i=0; sum[1] = 0;
        if (line[y][x] == '.') {
          //*******************************
          if (y-1>=0 && x-2>=0 && line[y-1][x-2]=='.') {beats++; sum[i] = howManyPositionsBeats(y-1,x-2,n); i++;}
          if (y+1<n && x-2>=0 && line[y+1][x-2]=='.') {beats++; sum[i] = howManyPositionsBeats(y+1,x-2,n); i++;}
          if (y-2>=0 && x-1>=0 && line[y-2][x-1]=='.') {beats++; sum[i] = howManyPositionsBeats(y-2,x-1,n); i++;}
          if (y+2<n && x-1>=0 && line[y+2][x-1]=='.') {beats++; sum[i] = howManyPositionsBeats(y+2,x-1,n); i++;}
          if (y-2>=0 && x+1<3 && line[y-2][x+1]=='.') {beats++; sum[i] = howManyPositionsBeats(y-2,x+1,n); i++;}
          if (y+2<n && x+1<3 && line[y+2][x+1]=='.') {beats++; sum[i] = howManyPositionsBeats(y+2,x+1,n); i++;}
          if (y-1>=0 && x+2<3 && line[y-1][x+2]=='.') {beats++; sum[i] = howManyPositionsBeats(y-1,x+2,n); i++;}
          if (y+1<n && x+2<3 && line[y+1][x+2]=='.') {beats++; sum[i] = howManyPositionsBeats(y+1,x+2,n); i++;}

          //*******************************
          if (beats==1 && sum[0]==4) found = true;
          if (0<beats && beats<3 && (beats<theBest.beats || (beats==theBest.beats && sprawdz(theBest,sum[0],sum[1])) ) ) {
              exists = true;
              theBest.y = y; theBest.x = x; theBest.beats = beats; theBest.sum1 = sum[0], theBest.sum2 = sum[1];
          }
        }
      }
    }
    if(exists) {
      result++;
      line[theBest.y][theBest.x] = 'S';
      lock(theBest.y,theBest.x,n);
    }
  }

  //CHANGE '.' to 'S'******************************
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++) {
      if (line[y][x]=='.') {
        result++;
        line[y][x] = 'S';
      }
    }
  }
  //CHANGE 'Z' to '.'******************************
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++) {
      if (line[y][x]=='Z') line[y][x] = '.';
    }
  }

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
