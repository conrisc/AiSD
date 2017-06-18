#include <cstdio>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <iostream>

#define MAX_N 500000

using namespace std;

struct Vertex {
  list <int> neighbours;
  string name;
  int parent;
};

struct Level {
  list <int> v;
};

struct helpV {
  int id;
  string name;
};

// bool comparator (helpV a, helpV b) {
//   if (a.name < b.name) return true;
//   return false;
// }

bool operator<(helpV a, helpV b) {
  if (a.name < b.name) return true;
  return false;
}

bool operator==(helpV a, helpV b) {
  if (a.name == b.name) return true;
  return false;
}

int findHeight(Vertex (*T)[2][MAX_N],int t, int v,int level,int parent) {
  (*T)[t][v].name = to_string(level);
  (*T)[t][v].parent = parent;
  if (parent!=-1 && (*T)[t][v].neighbours.size()==1) return 1;
  int max_h = 0,h;
  for( list<int>::const_iterator it = (*T)[t][v].neighbours.begin(); it != (*T)[t][v].neighbours.end(); it++ ) {
    if (*it!=parent) {
      h = findHeight(T,t,*it,level+1,v);
      if (max_h<h) max_h=h;
    }
  }
  return max_h + 1;
}

void create_name(Vertex (*T)[2][MAX_N],int t, int v) {
  if((*T)[t][v].parent!=-1 && (*T)[t][v].neighbours.size()==1) (*T)[t][v].name = "0";
  else {
    vector <string> names;
    for(list<int>::const_iterator it = (*T)[t][v].neighbours.begin(); it != (*T)[t][v].neighbours.end(); it++ ) {
      if ((*T)[t][v].parent != *it)
        names.push_back((*T)[t][*it].name);
    }
    sort(names.begin(),names.end());
    (*T)[t][v].name = names[0];
    for (size_t i=1;i<names.size();i++) {
      (*T)[t][v].name += "."+names[i];
    }
  }
}

int main() {

  int d,n,a,b,height,temp_l;

  scanf("%d",&d);
  for (int z=0;z<d;z++) {
    //SCANF****************************************
    scanf("%d",&n);
    Vertex T[2][MAX_N];
    for (int j=0;j<2;j++) {
      for (int i=0;i<n-1;i++) {
        scanf("%d %d",&a,&b); a=a-1; b=b-1;
        T[j][a].neighbours.push_back(b);
        T[j][b].neighbours.push_back(a);
      }
    }
    //CHOOSE ROOT1*********************************
    int root1 = 0;
    height = findHeight(&T,0,root1,0,-1);
    Level levelofT[2][height];
    for (int i=0;i<n;i++) {
      temp_l = stoi(T[0][i].name);
      levelofT[0][temp_l].v.push_back(i);
    }



    bool yup = false;
          for (int root2=0;root2<n;root2++) {
              yup = true;
              if (T[0][root1].neighbours.size()!=T[1][root2].neighbours.size()) yup=false;
              //CREATE_LEVELS_TABLE**************************
              if (yup && findHeight(&T,1,root2,0,-1)!=height) yup = false;
              for (int i=0;yup && i<n;i++) {
                temp_l = stoi(T[1][i].name);
                levelofT[1][temp_l].v.push_back(i);
              }
              //MAIN*****************************************
              for (int lvl=height-1;yup && lvl>=0;lvl--) {
                if (levelofT[0][lvl].v.size()!=levelofT[1][lvl].v.size()) yup = false;
                //create_names
                for (int j=0;yup && j<2;j++) {
                  for(list<int>::const_iterator it = levelofT[j][lvl].v.begin(); it != levelofT[j][lvl].v.end(); it++ )
                    create_name(&T,j,*it);
                }
                //sort_names
                vector <helpV> names[2];
                for (int j=0;yup && j<2;j++) {
                  for(list<int>::const_iterator it = levelofT[j][lvl].v.begin(); it != levelofT[j][lvl].v.end(); it++ ) {
                    helpV temp; temp.id = *it; temp.name = T[j][*it].name;
                    names[j].push_back(temp);
                  }
                  if (yup) sort(names[j].begin(),names[j].end());
                }
                //compare
                if (yup && names[0].size()!=names[1].size()) yup = false;
                else {
                  for (size_t i=0;i<names[0].size() && yup;i++) {
                    if (names[0][i].name!=names[1][i].name) yup = false;
                  }
                }
                //simplify_names
                for (int j=0;j<2 && yup;j++) {
                  int is = 1;
                  T[j][names[j][0].id].name = to_string(is);
                  for (size_t i=1;i<names[j].size() && yup;i++) {
                    if (names[j][i-1].name!=names[j][i].name) is++;
                    T[j][names[j][i].id].name = to_string(is);
                  }
                }
              }
              //****************************
              if (yup == true) break;
              else {
                for (int i=0;i<height;i++) {
                  levelofT[1][i].v.clear();
                }
              }
          }
    if (yup) printf("TAK\n");
    else printf("NIE\n");




    //PRINTF***************************************
    // for (int j=0;j<2;j++) {
    //   printf("Tree %d:\n",j+1);
    //   for (int i=0;i<n;i++) {
    //     printf(" %d:",i+1);
    //     for( list<int>::const_iterator it = T[j][i].neighbours.begin(); it != T[j][i].neighbours.end(); it++ )
    //        printf( " %d", *it+1 );
    //     printf("\n");
    //   }
    // }

    // for (int j=0;j<2;j++) {
    //   printf("Tree %d:\n",j+1);
    //   for (int i=0;i<height;i++) {
    //     printf(" %d:",i+1);
    //     for( list<int>::const_iterator it = levelofT[j][i].v.begin(); it != levelofT[j][i].v.end(); it++ )
    //       printf( " %d", *it+1 );
    //     printf("\n");
    //   }
    // }
    // for (int j=0;j<2;j++) {
    //   printf("Tree %d:\n",j+1);
    //   for (int i=0;i<n;i++) {
    //     printf(" %d: ",i+1);
    //     for (int s=0;s<T[j][i].name.size();s++) printf("%c",T[j][i].name[s]);
    //     printf("\n");
    //   }
    // }

    //*********************************************
  }
  return 0;
}
