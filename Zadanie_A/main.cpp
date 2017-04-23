#include <cstdio>

using namespace std;

int main () {

  int n,m,cities = 0,id;
  bool isNew;
  scanf("%d %d",&n,&m);
  char line[m+1];
  int *pointer[m];
  int ids[m];
  bool licznik[m];
  for (int i=0;i<m;i++) {
    pointer[i] = NULL;
    licznik[i] = false;
  }

  for (int i=0;i<n;i++) {
    fgets (line, 2, stdin);   //reads new line character
    fgets (line, m+1, stdin);

    for (int j=0;j<m;j++) {
      if (line[j]=='A' || line[j]=='B' || line[j]=='E' || pointer[j]==NULL)
        pointer[j] = NULL;
      else {
        licznik[*pointer[j]] = true;
        pointer[j] = &ids[*pointer[j]];
      }
    }

    for (int j=0;j<m;j++) ids[j] = j;

    id = 0;
    isNew = true;
    for (int j=0;j<m;j++) {
      switch(line[j]) {
        case 'A':
          isNew = true;
          pointer[j] = NULL;
          break;
        case 'B':
          if (isNew) {
            cities++;
            while(licznik[id]==true) {id++;}
            pointer[j] = &ids[id];
            id++;
          }
          else {
            pointer[j] = pointer[j-1];
          }
          isNew = true;
          break;
        case 'C':
          if (isNew && pointer[j]==NULL) {
            cities++;
          }
          else if (!isNew && pointer[j]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            *pointer[j] = *pointer[j-1];
            pointer[j-1] = pointer[j];
          }
          isNew = true;
          pointer[j] = NULL;
          break;
        case 'D':
          if (pointer[j]==NULL) {
            cities++;
            while(licznik[id]==true) {id++;}
            pointer[j] = &ids[id];
            id++;
          }
          isNew = false;
          break;
        case 'E':
          cities++;
          while(licznik[id]==true) {id++;}
          pointer[j] = &ids[id];
          id++;
          isNew = false;
          break;
        case 'F':
          if(isNew && pointer[j]==NULL) {
            cities++;
            while(licznik[id]==true) {id++;}
            pointer[j] = &ids[id];
            id++;
          }
          else if (!isNew && pointer[j]!=NULL && *pointer[j-1] != *pointer[j]) {
            cities--;
            *pointer[j] = *pointer[j-1];
            pointer[j-1] = pointer[j];
          }
          else if (!isNew){
            pointer[j] = pointer[j-1];
          }
          isNew = false;
          break;
      }
    }

    for (int j=0;j<m;j++) {
      if (line[j]=='D') pointer[j]=NULL;
      licznik[j] = false;
    }
    printf(" %d \n", cities);
  }

  printf("%d\n",cities);

  return 0;
}
