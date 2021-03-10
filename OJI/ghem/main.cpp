#include <fstream>
using namespace std;
ifstream  fin("ghem.in");
ofstream fout("ghem.out");
int n,x,y,i,j,k,p,a[502][502];
char d;
void rama(int p, int k){
    ///(k,k)    - (k,n+1-k)
    ///  |              |
    ///(n+1-k,k)- (n+1-k,n+1-k)
    if(p==0){
        int i=k, j=k;
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        return;
    }
    if(p==1){
        int i=k, j=n+1-k;
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        return;
    }
    if(p==2){
        int i=n+1-k, j=n+1-k;
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        return;
    }
    if(p==3){
        int i=n+1-k, j=k;
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        return;
    }
    if(p==4){
        int i=k, j=k;
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        return;
    }
    if(p==5){
        int i=n+1-k, j=k;
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        return;
    }
    if(p==6){
        int i=n+1-k, j=n+1-k;
        while(i>k){fout<<a[i][j]<<" "; i--;};
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        return;
    }
    if(p==7){
        int i=k, j=n+1-k;
        while(j>k){fout<<a[i][j]<<" "; j--;};
        while(i<n+1-k){fout<<a[i][j]<<" "; i++;};
        while(j<n+1-k){fout<<a[i][j]<<" "; j++;};
        while(i>k){fout<<a[i][j]<<" "; i--;};
        return;
    }
}
int main()
{
    int r=0;
    fin>>n>>x>>y>>d;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            r++; a[i][j]=r;
        }
    }
    if(d=='O' && x==1 && y==1)p=0;
    if(d=='V' && x==1 && y==1)p=4;
    if(d=='V' && x==1 && y==n)p=1;
    if(d=='O' && x==1 && y==n)p=7;
    if(d=='O' && x==n && y==n)p=2;
    if(d=='V' && x==n && y==n)p=6;
    if(d=='V' && x==n && y==1)p=3;
    if(d=='O' && x==n && y==1)p=5;
    for(k=1;k<=n/2;k++){
        rama(p,k);
    }
    if(n%2==1){
        fout<<a[n/2+1][n/2+1];
    }
    fin.close();
    fout.close();
    return 0;
}
