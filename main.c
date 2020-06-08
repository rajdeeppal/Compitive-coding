#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int group[n];
    for(int i=0;i<n;i++)
        scanf("%d",&group[i]);
    int DP[4][n+1];

    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j>0)
                DP[i][j]=0;
            else if(j==0)
                DP[i][j]=1;
            else if(group[j]==1)
                DP[i][j]=0;
            else if(j<i)
                DP[i][j]=DP[i-1][j];
            else if(j>=i){
                if(group[j-i]==0){
                    DP[i][j]=1;
                }
                else
                    DP[i][j]=0;
            }


        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            printf("%d ",DP[i][j]);
        }
        printf("\n");
    }
    int cr=0;
    int crIn;
    int pre=0;
    int ct=0;
for(int j=0;j<n;j++){
    pre=cr;
    cr=DP[2][j];
    if(cr == 0&& pre == 0){
        crIn=j-1;
        for(int i=crIn;i<=j;i++){
            if(DP[1][i]==1){
                DP[2][i]=1;
                break;
            }
        }
    }

}
for(int j=1;j<n;j++){
    if(DP[2][j]==1)
        ct++;
}

printf("\n\n\n\n\n\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            printf("%d ",DP[i][j]);
        }
        printf("\n");
    }
printf("\n\n\n\n\n\n");
printf("%d",ct);    //printf("Hello world!\n");
    return 0;
}
