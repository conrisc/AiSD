// Konrad Cielecki
// nr indeksu: 273278
// grupa cwiczeniowa: MSZ
#include <cstdio>

using namespace std;

int main() {
    int a,b,i;
    scanf("%d %d",&a,&b);
    if(a%2==0)
        i=a+1;
    else
        i=a;

    for (;i<=b;i+=2) {
        printf("%d ",i);
    }

    return 0;
}
