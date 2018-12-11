#include<iostream>
using namespace std;
// App BKTR : alg generare permutari ( iterativ )
int n; // cardinalul multimii M = {1,2,3 , ... ,n }
int ST[100];
int vf;

int init(int S[],int top)
{S[top]=0;}

int tipar(int S[],int top)
{cout<<endl;
for(int i=1;i<=top;i++) cout<<S[i]<<" "; }

int solutie(int S[],int top)
{if (top==n) return 1;
          else return 0;}

int succesor(int S[],int top)
{ if (S[top]<n)  { S[top]++;return 1;}
                else return 0;  }

int valid(int S[],int top)
{if (top==1)  return 1;
else {
        for(int i=1;i<top;i++)
        {if (S[i]==S[top]) return 0;}
        return 1;} }

 int bktr_it()
 {
 vf=1;
init(ST,vf);
while (vf>=1) { // atata timp cat inca mai sunt modalitati de a
                        // alege un prim element ( de a incepe sa
                        // construiesc solutia )
                        // caut succesor valid la varf curent pe stiva
                        int am; // 0 sau 1 dupa cum am sau nu succesor
                                    // la varf curent pe stiva
                        int este;// 0 sau 1 dupa cum succesorul depus la varf curent
                                    // este sau nu admisibil ( adica valid )
                       do {
                             am=succesor(ST,vf);
                             este=valid(ST,vf);
                            } while(!((am&&este)||(!am)));
                       if (am) { if (solutie(ST,vf)) tipar(ST,vf);
                                                        else { vf++;
                                                                  init(ST,vf);}
                                  }
                           else vf--;
                   }
return 0;}

int main()
{cout<<"n=";cin>>n;
  bktr_it();
return 0;}

// Apps :
// De modificat pentru a lucra cu un obiect de tip stiva
/*
Adica stiva sa nu fie
int S[100];
int vf;
ci sa fie

class stack {
                    private :
                    int vf;
                    int S[100];
                    public :
                    push(int value) { ... }
                    pop(int value) { ... }
                    isempty() { ... }
                    whathight() { .... }
                    stack() { vf=0; }
                   }
stack somestack();
int init(stack this_stack) { ... }
....

*/
