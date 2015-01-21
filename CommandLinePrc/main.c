#include<stdio.h>
#include<stdlib.h>

/*找出第n大的数的下标*/
int choose_nth(int a[], int startIndex, int endIndex, int n);

/*找出前n大的数*/
void choose_max_n(int a[],int startIndex, int endIndex, int n);



void choose_max_n(int a[], int startIndex, int endIndex, int n)
{
    int i = choose_nth(a, startIndex, endIndex, n);
    
    printf("最大的前N个数是:\n");
    for(; i <= endIndex; ++i)
        printf("%d ",a[i]);
    printf("\n");
}


int choose_nth(int a[], int startIndex, int endIndex, int n)
{
    int midOne = a[startIndex];
    int i = startIndex, j = endIndex;
    if(i == j)
        return i;
    
    if(i < j)
    {
        while(i < j)
        {
            for(; i < j; j--)
                if(a[j] < midOne)
                {
                    a[i++] = a[j];
                    break;
                }
            
            for(; i < j; i++)
                if(a[i] > midOne)
                {
                    a[j--] = a[i];
                    break;
                }
            
        }
        
        a[i] = midOne;
        int th = endIndex - i + 1;
        
        if(th == n)
        {
            return i;
        }
        else
        {
            if(th > n)
            {
                return choose_nth(a, i + 1, endIndex, n);
            }
            else
            {
                return choose_nth(a, startIndex, i - 1, n - th);
            }
        }
        
    }
    return (1<<30)-2;
}

int main(int argc, char **argv)
{
    int a[] = {1,4,111,32,45,1000,99,300,8,22,189};
    int n,i;
    printf("数组是:\n");
    int an = sizeof(a)/sizeof(int);
    for(i = 0; i < an; ++i)
        printf("%d ",a[i]);
    printf("\n");
    
    printf("你想找最大的前面几个数:");
    scanf("%d",&n);
    
    choose_max_n(a, 0, an - 1, n);
    
    return 0;
}
