#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
mt19937 mtrand(time(0));
int rd(int l,int r)
{
    return mtrand() % (r - l) + l;
}
int A[MAXN];
void QuickSort(int *A,int l,int r)
{
    if(l >= r) return ;
    random_shuffle(A + l,A + r + 1);
    int bd = A[l],p = l,q = r;
    while(p < q)
    {
        while(p < q && A[q] >= bd) --q;
        A[p] = A[q];
        while(p < q && A[p] <= bd) ++p;
        A[q] = A[p];
    }
    A[p] = bd;
    QuickSort(A,l,p - 1);
    QuickSort(A,p + 1,r);
}
int main()
{
    int n = 10;
    for(int i = 1; i <= n; ++i)
        A[i] = rd(1,100);
    cout << "pre sort:" << endl;
    for(int i = 1; i <= n; ++i) cout << A[i] << " ";
    cout << endl;
    QuickSort(A,1,n);
    cout << "after sort:" << endl;
    for(int i = 1; i <= n; ++i) cout << A[i] << " ";
    cout << endl;
    return 0;
}