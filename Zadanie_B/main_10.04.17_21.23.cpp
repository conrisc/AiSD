#include <cstdio>
#include <list>

using namespace std;

struct Coordinates {
  int y,x;
};

char line[1000000][4];
list <Coordinates> b1[4];
list <Coordinates> b2[8];

int main () {

  int n,result=0;
  scanf("%d",&n);

  for (int i=0;i<n;i++) {
    fgets (line[i], 2, stdin);
    fgets (line[i], 4, stdin);
  }

  for (int i=0;i<n;i++) {
    //j==0;
    if (line[i][0] == '.') {
      line[i][0] = '0';
      if (i-2>=0 && line[i-2][1]<52) {line[i][0]++; line[i-2][1]++;}
      if (i-1>=0 && line[i-1][2]<52) {line[i][0]++; line[i-1][2]++;}
    }
    //j==1;
    if (line[i][1] == '.') {
      line[i][1] = '0';
      if (i-2>=0 && line[i-2][0]<52) {line[i][1]++; line[i-2][0]++;}
      if (i-2>=0 && line[i-2][2]<52) {line[i][1]++; line[i-2][2]++;}
    }
    //j==2;
    if (line[i][2] == '.') {
      line[i][2] = '0';
      if (i-2>=0 && line[i-2][1]<52) {line[i][2]++; line[i-2][1]++;}
      if (i-1>=0 && line[i-1][0]<52) {line[i][2]++; line[i-1][0]++;}
    }
  }

  int sum;
  for (int i=0;i<n;i++) {
    //j==0;
    if (line[i][0] == '1' || line[i][0]=='2') {
      sum=0;
      if (i-2>=0 && line[i-2][1]<53) {sum+=line[i-2][1]-48;}
      if (i-1>=0 && line[i-1][2]<53) {sum+=line[i-1][2]-48;}
      if (i+1<n && line[i+1][2]<53) {sum+=line[i+1][2]-48;}
      if (i+2<n && line[i+2][1]<53) {sum+=line[i+2][1]-48;}
      Coordinates temp; temp.y = i; temp.x = 0;
      if (line[i][0]=='1') { b1[sum-1].push_back(temp);}
      else {b2[sum-1].push_back(temp);}
    }
    //j==1;
    if (line[i][1] == '1' || line[i][1]=='2') {
      sum=0;
      if (i-2>=0 && line[i-2][0]<53) {sum+=line[i-2][0]-48;}
      if (i-2>=0 && line[i-2][2]<53) {sum+=line[i-2][2]-48;}
      if (i+2<n && line[i+2][0]<53) {sum+=line[i+2][0]-48;}
      if (i+2<n && line[i+2][2]<53) {sum+=line[i+2][2]-48;}
      Coordinates temp; temp.y = i; temp.x = 1;
      if (line[i][1]=='1') { b1[sum-1].push_back(temp);}
      else {b2[sum-1].push_back(temp);}
    }
    //j==2;
    if (line[i][2] == '1' || line[i][2]=='2') {
      sum=0;
      if (i-2>=0 && line[i-2][1]<53) {sum+=line[i-2][1]-48;}
      if (i-1>=0 && line[i-1][0]<53) {sum+=line[i-1][0]-48;}
      if (i+1<n && line[i+1][0]<53) {sum+=line[i+1][0]-48;}
      if (i+2<n && line[i+2][1]<53) {sum+=line[i+2][1]-48;}
      Coordinates temp; temp.y = i; temp.x = 2;
      if (line[i][2]=='1') { b1[sum-1].push_back(temp);}
      else {b2[sum-1].push_back(temp);}
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
