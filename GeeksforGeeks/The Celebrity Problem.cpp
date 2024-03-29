/*
You are in a party of N people, where only one person is known to everyone. Such a person may be present in the party, if yes, (s)he doesn�t know anyone in the party. Your task is to find the stranger (celebrity) in party.
You will be given a square matrix M where if an element of row i and column j  is set to 1 it means there is an edge from ith person to jth person. An edge represent the relation that i th person knows j th person. You need to complete the function getId which finds the id of the celebrity if present else return -1. The function getId takes two arguments the square matrix M and its size n.
*/
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    stack<int> celeb;
    for(int i=0;i<n;++i)
        celeb.push(i);
    int a=celeb.top();
    celeb.pop();
    int b=celeb.top();
    celeb.pop();
    while(celeb.size()>1){
        if(M[a][b]){
            a=celeb.top();
            celeb.pop();
        }
        else{
            b=celeb.top();
            celeb.pop();
        }
    }
    int c=celeb.top();
    if(M[c][b])
        c=b;

    if(M[c][a])
        c=a;

    for(int i=0;i<n;++i)
        if(i!=c and (!M[i][c] or M[c][i]))
            return -1;
    return c;

}
