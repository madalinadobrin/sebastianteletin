/*
BKTR :

[1] Generarii permutarilor unei multimi de n elemente
(a) BKTR it [x]
(b) BKTR rec [?]
[2] Generarii tuturor aranjamentelor de k elemente dintr-o
multime de n elemente
[3] Generarii tuturor aranjamentelor fara repetitie ( combinari )
de k elemente dintr-o  multime de n elemente

*/
#include<iostream>
using namespace std;
int ST[100];
int n;
int vf;

int init(int S[],int top)
{S[top]=0;}

int tipar(int S[],int top)
{
 cout<<endl;
 for(int i=1;i<top;i++) cout<<" "<<S[i];
}

int solutie(int S[],int top)
{
if (top==(n+1) ) return 1;
else return  0;
}

int succesor(int S[],int top)
{
if (S[top]<n)  {
                        S[top]++;
                        return 1;
                    }
else return 0;
}

int valid(int S[],int top)
{
if (top==1) return 1;
else
        for(int i=1;i<top;i++)
        {
            if (S[i]==S[top])  return 0;
        }
        return 1;
}

int BKTR_rec(int S[],int top)
{
 if (solutie(S,top)) { tipar(S,top);}
 while (succesor(S,top))
    {
      if ( valid(S,top) ) {
                                 init(S,top+1);
                                 BKTR_rec(S,top+1);
                               }
    }
 return 0; }

 int main()
 {
 cout<<" N=";cin>>n;
 init(ST,1);
 BKTR_rec(ST,1);
 }
