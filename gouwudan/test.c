#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)>(y)?(y):(x)

int index1(int i,int q[],int m)
{
    int count = 0;
    for(int j = 0;j<m;j++)
    {
        if(q[j+1] == i)
        {
            count++;
        }
    }
    return count;
}

int main()
 {
    int N,m;
    scanf("%d %d",&N,&m);
    int arr[m+1][N+1];
    int v[m+1];
    int p[m+1];
    int q[m+1];
    int tmp[2] = {0};
    memset(arr,0,sizeof(arr));
    memset(v,0,sizeof(v));
    memset(p,0,sizeof(p));
    memset(q,0,sizeof(q));

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &v[i + 1], &p[i + 1], &q[i + 1]);
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= N; j = j + 10)
        {
            if (v[i] > j || q[i] > 0)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else if (v[i] <= j && q[i] == 0 && index1(i, q, m) == 0)
            {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - v[i]] + v[i] * p[i]);
            }
            else if (v[i] <= j && q[i] == 0 && index1(i, q, m) == 1)
            {
                int k = 0;
                for (k = 0; k < m; k++)
                {
                    if (q[k + 1] == i)
                    {
                        break;
                    }
                }
                if (j >= (v[i] + v[k + 1]))
                {
                    int tmp = max(arr[i - 1][j], arr[i - 1][j - v[i] - v[k + 1]] + v[i] * p[i] + v[k + 1] * p[k + 1]);
                    arr[i][j] = max(tmp, arr[i - 1][j - v[i]] + v[i] * p[i]);
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - v[i]] + v[i] * p[i]);
                }

            }
            else if (v[i] <= j && q[i] == 0 && index1(i, q, m) == 2)
            {
                int k = 0;
                int k1 = 0;
                for (k = 0; k < m; k++)
                {
                    if (q[k + 1] == i)
                    {
                        tmp[k1] = k + 1;
                        k1++;
                    }
                }
                int tmp0 = max(v[tmp[0]], v[tmp[1]]);
                int tmp3 = min(v[tmp[0]], v[tmp[1]]);
                v[tmp[0]] = tmp0;
                v[tmp[1]] = tmp3;
                if (j >= (v[i] + v[tmp[0]] + v[tmp[1]]))
                {
                    int tmp1 = max(arr[i - 1][j], arr[i - 1][j - v[i] - v[tmp[0]]] + v[i] * p[i] + v[tmp[0]] * p[tmp[0]]);
                    int tmp2 = max(tmp1, arr[i - 1][j - v[i] - v[tmp[1]]] + v[i] * p[i] + v[tmp[1]] * p[tmp[1]]);
                    int tmp4 = max(tmp2, arr[i - 1][j - v[i]] + v[i] * p[i]);
                    arr[i][j] = max(tmp4, arr[i - 1][j - v[i] - v[tmp[1]] - v[tmp[0]]] + v[i] * p[i] + v[tmp[1]] * p[tmp[1]] + v[tmp[0]] * p[tmp[0]]);
                }
                else if (j >= (v[i] + v[tmp[0]]))
                {
                    int tmp1 = max(arr[i - 1][j], arr[i - 1][j - v[i] - v[tmp[0]]] + v[i] * p[i] + v[tmp[0]] * p[tmp[0]]);
                    int tmp2 = max(tmp1, arr[i - 1][j - v[i]] + v[i] * p[i]);
                    arr[i][j] = max(tmp2, arr[i - 1][j - v[i] - v[tmp[1]]] + v[i] * p[i] + v[tmp[1]] * p[tmp[1]]);
                }
                else if (j >= (v[i] + v[tmp[1]]))
                {
                    int tmp1 = max(arr[i - 1][j], arr[i - 1][j - v[i] - v[tmp[1]]] + v[i] * p[i] + v[tmp[1]] * p[tmp[1]]);
                    arr[i][j] = max(tmp1, arr[i - 1][j - v[i]] + v[i] * p[i]);
                }
                else
                {
                    arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - v[i]] + v[i] * p[i]);
                }
            }
        }
    }
    printf("%d", arr[m][N]);
    return 0;
}