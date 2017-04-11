#include <cstdio>
#include <list>

using namespace std;

struct Coordinates {
  int y,x;
};

char line[1000000][4];
list <Coordinates> b1[4];
list <Coordinates> b2[8];

void add(int y, int x, int n) {
  int sum=0;
  int beats=0;
  if (y-1>=0 && x-2>=0 && 48<line[y-1][x-2] && line[y-1][x-2]<53) {beats++; sum+=line[y-1][x-2]-48;}
  if (y+1<n && x-2>=0 && 48<line[y+1][x-2] && line[y+1][x-2]<53) {beats++; sum+=line[y+1][x-2]-48;}
  if (y-2>=0 && x-1>=0 && 48<line[y-2][x-1] && line[y-2][x-1]<53) {beats++; sum+=line[y-2][x-1]-48;}
  if (y+2<n && x-1>=0 && 48<line[y+2][x-1] && line[y+2][x-1]<53) {beats++; sum+=line[y+2][x-1]-48;}
  if (y-2>=0 && x+1<3 && 48<line[y-2][x+1] && line[y-2][x+1]<53) {beats++; sum+=line[y-2][x+1]-48;}
  if (y+2<n && x+1<3 && 48<line[y+2][x+1] && line[y+2][x+1]<53) {beats++; sum+=line[y+2][x+1]-48;}
  if (y-1>=0 && x+2<3 && 48<line[y-1][x+2] && line[y-1][x+2]<53) {beats++; sum+=line[y-1][x+2]-48;}
  if (y+1<n && x+2<3 && 48<line[y+1][x+2] && line[y+1][x+2]<53) {beats++; sum+=line[y+1][x+2]-48;}
  Coordinates temp; temp.y=y, temp.x=x;
  if(beats==1) {b1[sum-1].push_back(temp);}
  else if(beats==2) {b2[sum-1].push_back(temp);}
}

void addToList(int y, int x, int n) {
  if (y-1>=0 && x-2>=0 && 48<line[y-1][x-2] && line[y-1][x-2]<53) {add(y-1,x-2,n);}
  if (y+1<n && x-2>=0 && 48<line[y+1][x-2] && line[y+1][x-2]<53) {add(y+1,x-2,n);}
  if (y-2>=0 && x-1>=0 && 48<line[y-2][x-1] && line[y-2][x-1]<53) {add(y-2,x-1,n);}
  if (y+2<n && x-1>=0 && 48<line[y+2][x-1] && line[y+2][x-1]<53) {add(y+2,x-1,n);}
  if (y-2>=0 && x+1<3 && 48<line[y-2][x+1] && line[y-2][x+1]<53) {add(y-2,x+1,n);}
  if (y+2<n && x+1<3 && 48<line[y+2][x+1] && line[y+2][x+1]<53) {add(y+2,x+1,n);}
  if (y-1>=0 && x+2<3 && 48<line[y-1][x+2] && line[y-1][x+2]<53) {add(y-1,x+2,n);}
  if (y+1<n && x+2<3 && 48<line[y+1][x+2] && line[y+1][x+2]<53) {add(y+1,x+2,n);}
}

void decrease(int y,int x,int n) {
  line[y][x]='Z';
  if (y-1>=0 && x-2>=0 && 48<line[y-1][x-2] && line[y-1][x-2]<53) {line[y-1][x-2]--;}
  if (y+1<n && x-2>=0 && 48<line[y+1][x-2] && line[y+1][x-2]<53) {line[y+1][x-2]--;}
  if (y-2>=0 && x-1>=0 && 48<line[y-2][x-1] && line[y-2][x-1]<53) {line[y-2][x-1]--;}
  if (y+2<n && x-1>=0 && 48<line[y+2][x-1] && line[y+2][x-1]<53) {line[y+2][x-1]--;}
  if (y-2>=0 && x+1<3 && 48<line[y-2][x+1] && line[y-2][x+1]<53) {line[y-2][x+1]--;}
  if (y+2<n && x+1<3 && 48<line[y+2][x+1] && line[y+2][x+1]<53) {line[y+2][x+1]--;}
  if (y-1>=0 && x+2<3 && 48<line[y-1][x+2] && line[y-1][x+2]<53) {line[y-1][x+2]--;}
  if (y+1<n && x+2<3 && 48<line[y+1][x+2] && line[y+1][x+2]<53) {line[y+1][x+2]--;}
}

bool checkAndEdit1(int y,int x,int n,int sum) {
  //CHECK
  if (line[y][x]!='1') return false;
  int realSum=0;
  Coordinates remember;
  if (y-1>=0 && x-2>=0 && 48<line[y-1][x-2] && line[y-1][x-2]<53) {realSum=line[y-1][x-2]-48; remember.y=y-1;remember.x=x-2;}
  if (y+1<n && x-2>=0 && 48<line[y+1][x-2] && line[y+1][x-2]<53) {realSum=line[y+1][x-2]-48; remember.y=y+1;remember.x=x-2;}
  if (y-2>=0 && x-1>=0 && 48<line[y-2][x-1] && line[y-2][x-1]<53) {realSum=line[y-2][x-1]-48; remember.y=y-2;remember.x=x-1;}
  if (y+2<n && x-1>=0 && 48<line[y+2][x-1] && line[y+2][x-1]<53) {realSum=line[y+2][x-1]-48; remember.y=y+2;remember.x=x-1;}
  if (y-2>=0 && x+1<3 && 48<line[y-2][x+1] && line[y-2][x+1]<53) {realSum=line[y-2][x+1]-48; remember.y=y-2;remember.x=x+1;}
  if (y+2<n && x+1<3 && 48<line[y+2][x+1] && line[y+2][x+1]<53) {realSum=line[y+2][x+1]-48; remember.y=y+2;remember.x=x+1;}
  if (y-1>=0 && x+2<3 && 48<line[y-1][x+2] && line[y-1][x+2]<53) {realSum=line[y-1][x+2]-48; remember.y=y-1;remember.x=x+2;}
  if (y+1<n && x+2<3 && 48<line[y+1][x+2] && line[y+1][x+2]<53) {realSum=line[y+1][x+2]-48; remember.y=y+1;remember.x=x+2;}
  if (sum!=realSum) {
    Coordinates temp; temp.y=y; temp.x=x;
    b1[realSum-1].push_back(temp);
    return false;
  }
  //EDIT
  line[y][x] = 'S';
  decrease(remember.y,remember.x,n);
  addToList(remember.y,remember.x,n);
  return true;
}

bool checkAndEdit2(int y,int x,int n,int sum) {
  //CHECK
  if (line[y][x]!='2') return false;
  int realSum=0;
  int i=0;
  Coordinates remember[2];
  if (y-1>=0 && x-2>=0 && 48<line[y-1][x-2] && line[y-1][x-2]<53) {realSum+=line[y-1][x-2]-48; remember[i].y=y-1;remember[i].x=x-2;i++;}
  if (y+1<n && x-2>=0 && 48<line[y+1][x-2] && line[y+1][x-2]<53) {realSum+=line[y+1][x-2]-48; remember[i].y=y+1;remember[i].x=x-2;i++;}
  if (y-2>=0 && x-1>=0 && 48<line[y-2][x-1] && line[y-2][x-1]<53) {realSum+=line[y-2][x-1]-48; remember[i].y=y-2;remember[i].x=x-1;i++;}
  if (y+2<n && x-1>=0 && 48<line[y+2][x-1] && line[y+2][x-1]<53) {realSum+=line[y+2][x-1]-48; remember[i].y=y+2;remember[i].x=x-1;i++;}
  if (y-2>=0 && x+1<3 && 48<line[y-2][x+1] && line[y-2][x+1]<53) {realSum+=line[y-2][x+1]-48; remember[i].y=y-2;remember[i].x=x+1;i++;}
  if (y+2<n && x+1<3 && 48<line[y+2][x+1] && line[y+2][x+1]<53) {realSum+=line[y+2][x+1]-48; remember[i].y=y+2;remember[i].x=x+1;i++;}
  if (y-1>=0 && x+2<3 && 48<line[y-1][x+2] && line[y-1][x+2]<53) {realSum+=line[y-1][x+2]-48; remember[i].y=y-1;remember[i].x=x+2;i++;}
  if (y+1<n && x+2<3 && 48<line[y+1][x+2] && line[y+1][x+2]<53) {realSum+=line[y+1][x+2]-48; remember[i].y=y+1;remember[i].x=x+2;i++;}
  if (sum!=realSum) {
    Coordinates temp; temp.y=y; temp.x=x;
    b2[realSum-1].push_back(temp);
    return false;
  }
  //EDIT
  line[y][x] = 'S';
  decrease(remember[0].y,remember[0].x,n);
  decrease(remember[1].y,remember[1].x,n);
  addToList(remember[0].y,remember[0].x,n);
  addToList(remember[1].y,remember[1].x,n);
  return true;
}


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
  bool exists = true;
  Coordinates cand;
  while (exists) {
    exists = false;
    for (int i=3;i>=0 && !exists;i--) {
      while(!(b1[i].empty()) && !exists) {
        cand = b1[i].front();
        if (checkAndEdit1(cand.y,cand.x,n,i+1)) {exists = true; result++;}
        b1[i].pop_front();
      }
    }
    for (int i=7;i>=0 && !exists;i--) {
      while(!(b2[i].empty()) && !exists) {
        cand = b2[i].front();
        if (checkAndEdit2(cand.y,cand.x,n,i+1)) {exists = true; result++;}
        b2[i].pop_front();
      }
    }
  }

  for (int y=0;y<n;y++) {
    for (int x=0;x<3;x++) {
      if(line[y][x]=='0') {line[y][x] = 'S'; result++;}
      else if(line[y][x]=='Z') line[y][x] = '.';
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
