#include <stdio.h>

int a[10];
int one[4] = {0, 7, 6, 5};
int two[4] = {0, 5, 3, 1};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    int sum, ans, needOne, needTwo;
    while(1)
    {
        sum = 0;
        for(int i = 1; i <= 6; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if(!sum) break;
        ans = a[6] + a[5] + a[4] + (a[3] + 3) / 4;
        needOne = a[5] * 11 + one[a[3] % 4];
        needTwo = a[4] * 5 + two[a[3] % 4];
        if(needTwo <= a[2])
        {
            int left = a[2] - needTwo;
            int tmp = (left + 8) / 9;
            ans += tmp;
            needOne += 4 *(9 * tmp - left);
        }
        else
        {
            needOne += 4 * (needTwo - a[2]);
        }
        if(needOne <= a[1])
        {
            ans += (a[1] - needOne + 35) / 36;
        }
        printf("%d\n", ans);
    }
    return 0;
}
