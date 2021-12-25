// Ejercicio 5: Longest Common Substring
// Curso: Programación Competitiva
// Grupo: A
// Alumna: Fernanda Anthoanette Paredes Escobedo
// CUI: 20182906

#include <bits/stdc++.h>
using namespace std;

int n, m;
string A, B;
int dp[MAX_N][MAX_N];


inline int LCS()
{
    for (int i=0;i<=n;i++) dp[i][0] = 0;
    for (int j=0;j<=m;j++) dp[0][j] = 0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

inline string getLCS()
{
    string ret;
    stack<char> S;
    int ii = n, jj = m;
    while (ii != 0 && jj != 0)
    {
        if (A[ii-1] == B[jj-1])
        {
            S.push(A[ii-1]);
            ii--; jj--;
        }
        else if (dp[ii-1][jj] > dp[ii][jj-1]) ii--;
        else jj--;
    }
    while (!S.empty())
    {
        ret += S.top();
        S.pop();
    }
    return ret;
}

int main()
{
    n = 4, m = 2;
    A = "AABC";
    B = "BCDC";
    printf("%d\n",LCS());
    printf("%s\n",getLCS().c_str());
    return 0;
}
