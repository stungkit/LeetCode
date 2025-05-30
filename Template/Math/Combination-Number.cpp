using LL = long long;

/*********************************/
//  Version 1: compute all C(n,m) saved in comb
long long comb[1000][1000];  
for (int i = 0; i <= n; ++i) 
{
    comb[i][i] = comb[i][0] = 1;            
    if (i==0) continue;
    for (int j = 1; j < i; ++j) 
    {
        comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
}  

/*********************************/
//  Version 1.5: compute all C(n,m) saved in comb with maximum space capability
int comb[5001][2501];  
int getComb(int m, int n)
{
    if (m<n) return 0;
    if (n<=(m+1)/2)
        return comb[m][n];
    else
        return comb[m][m-n];
}
void precompute(int n)
{        
    for (int i = 0; i <= n; ++i) 
    {
        comb[i][0] = 1;
        if (i==0) continue;
        for (int j = 1; j <= (i+1)/2; ++j) 
        {
            comb[i][j] = getComb(i-1, j-1) + getComb(i-1,j);
            comb[i][j] = min(comb[i][j], INT_MAX/2);
        }
    }
}

/*********************************/
// Version 2: Compute C(n,m) on demand based on definition
long long help(int n, int m)
{
    long long cnt = 1;
    for(int i = 0; i < m; i++)
    {
        cnt *= n - i;
        cnt /= i + 1;
    }
    return cnt;
}

/*********************************/
// Version 3: Compute C(m,n) on demand with module M
using LL = long long;
LL M = 1e9+7;
vector<LL> factorial;

vector<LL> GetFactorial(LL N)
{
    vector<LL>rets(N+1);
    rets[0] = 1;
    for (int i=1; i<=N; i++)
        rets[i] = rets[i-1] * i % M;
    return rets;
}

long long quickPow(long long x, long long N) {
    if (N == 0) {
        return 1;
    }
    LL y = quickPow(x, N / 2) % M;
    return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
}

LL comb(LL m, LL n)
{
    if (n>m) return 0;
    LL a = factorial[m];
    LL b = factorial[n] * factorial[m-n] % M;
    LL inv_b = quickPow(b, (M-2));
    
    return a * inv_b % M;
}

/*********************************/
// Version 4: Compute C(m,n) on demand with module M
const LL MOD = 1e9 + 7;
vector<LL> factorial;
vector<LL> GetFactorial(LL N)
{
    vector<LL>rets(N+1);
    rets[0] = 1;
    for (int i=1; i<=N; i++)
        rets[i] = rets[i-1] * i % MOD;
    return rets;
}

long long quickPow(long long x, long long N) {
    if (N == 0) {
        return 1;
    }
    LL y = quickPow(x, N / 2) % MOD;
    return N % 2 == 0 ? (y * y % MOD) : (y * y % MOD * x % MOD);
}

LL comb(LL m, LL n)
{
    if (n>m) return 0;
    LL a = factorial[m];
    LL b = factorial[n] * factorial[m-n] % MOD;
    LL inv_b = quickPow(b, (MOD-2));

    return a * inv_b % MOD;
}
