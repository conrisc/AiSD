#include <cstdio>

using namespace std;

char line[1000000][4];

struct Position {
  int x,y,beats,sum;
};

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
  int beats, sum;
  while (exists) {
    exists = false; found=false;
    theBest.beats = 5; theBest.sum = 0;
    for (int y=0;y<n && !found;y++) {
      for (int x=0;x<3 && !found;x++) {
        beats = 0;
        sum = 0;
        if (line[y][x] == '.') {
          //*******************************
          if (y-1>=0 && x-2>=0 && line[y-1][x-2]=='.') {beats++; sum += howManyPositionsBeats(y-1,x-2,n);}
          if (y+1<n && x-2>=0 && line[y+1][x-2]=='.') {beats++; sum += howManyPositionsBeats(y+1,x-2,n);}
          if (y-2>=0 && x-1>=0 && line[y-2][x-1]=='.') {beats++; sum += howManyPositionsBeats(y-2,x-1,n);}
          if (beats<3 && y+2<n && x-1>=0 && line[y+2][x-1]=='.') {beats++; sum += howManyPositionsBeats(y+2,x-1,n);}
          if (beats<3 && y-2>=0 && x+1<3 && line[y-2][x+1]=='.') {beats++; sum += howManyPositionsBeats(y-2,x+1,n);}
          if (beats<3 && y+2<n && x+1<3 && line[y+2][x+1]=='.') {beats++; sum += howManyPositionsBeats(y+2,x+1,n);}
          if (beats<3 && y-1>=0 && x+2<3 && line[y-1][x+2]=='.') {beats++; sum += howManyPositionsBeats(y-1,x+2,n);}
          if (beats<3 && y+1<n && x+2<3 && line[y+1][x+2]=='.') {beats++; sum += howManyPositionsBeats(y+1,x+2,n);}

          //*******************************
          if (0<beats && beats<3 && (beats<theBest.beats || (beats==theBest.beats && theBest.sum<sum) ) ) {
              if (beats==1 && sum==4) found = true;
              exists = true;
              theBest.y = y; theBest.x = x; theBest.beats = beats; theBest.sum = sum;
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

  //CHANGE '.' to 'S || 'Z' to '.' ****************
  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++) {
      if (line[y][x]=='.') {
        result++;
        line[y][x] = 'S';
      }
      else if (line[y][x]=='Z')
        line[y][x] = '.';
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
