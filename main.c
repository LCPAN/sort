#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void insert_sort(int a[], int len)
{
    int i, j;
    for(i=1; i<len-1; i++)
    {
        j = i + 1;
        a[0] = a[j];
        while( (j> 1) && (a[j-1]>a[0]) )
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = a[0];
    }
}

void shell_insert_sort(int a[], int len, int x)
{
    int i, j;
    int tmp;
    for(i=x; i<len; i++)
    {
        if(a[i] < a[i-x])
        {
            j = i - x;
            tmp = a[i];
            a[i] = a[j];
            while( tmp > a[j] )
            {
                a[j-x] = a[j];
                j -= x;
            }
            a[j] = tmp;
        }
    }
}

void shell_sort(int a[], int len)
{
    int x;
     x = len / 2;
     while( x >= 1 )
     {
         shell_insert_sort(a, len, x);
         x = x / 2;
     }
}

void bubble_sort(int a[], int len)
{
    int i, j;

    for(i=0; i<len; i++)
    {
        for(j=0; j<len-1; j++)
        {
            if( a[j] > a[j+1] )
            {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void quick_sort(int a[], int s, int e)
{
    int i,j;
    int tmp;
    if( (e-s) <= 1 )
    {
        if( (e-s == 1) && (a[e] < a[s]) )
        {
            swap(&a[s], &a[e]);
        }
    }
    else
    {
        tmp = a[s];
        i = s;
        j = e;

        while( i!=j )
        {
            while( (j>i) && (a[j]>=tmp)) j--;
            while( (j>i) && (a[i]<=tmp)) i++;
            if(j > i)
            {
                swap(&a[i], &a[j]);
            }
        }
        a[s] = a[i];
        a[i] = tmp;

        quick_sort(a, s, i-1);
        quick_sort(a, i+1, e);
    }
}

void select_sort(int a[], int len)
{
    int i, j;
    int flag;
    for(i=0; i<len; i++)
    {
        flag = i;
        for(j=i+1 ; j<len; j++)
        {
            if( a[flag] > a[j] )
            {
                flag = j;
            }
        }
        if( i!=flag)
        {
            swap(&a[i], &a[flag]);
        }
    }
}

void maxheapify(int *a, unsigned int node, int Index)
{
	unsigned int l = ((node+1) << 1) - 1;
	unsigned int r = (node+1) << 1 ;
	unsigned int largest = node;
	unsigned int MaxIndex = Index;

	if(l <= MaxIndex && a[l] > a[node])
		largest = l ;

	if(r <= MaxIndex && a[r] > a[largest])
		largest = r ;

	if(largest!=node)
	{

		swap(&a[largest], &a[node]);
		maxheapify(a, largest, MaxIndex);
	}

}

void creat_heap(int a[], int length)
{
    int i;

    for(i = (length>>1)-1; i >=0; i--)
        maxheapify(a, i, length);
}

void heap_sort(int a[], int length)
{
    while( length > 0 )
    {
        swap(&a[length], &a[0]);
        length -= 1;
        maxheapify(a, 0, length);
    }
}

void merge(int a[], int s, int m, int e)
{
    int n1=m-s+1;
	int n2=e-m;

	int *left=(int *)malloc((n1+1)*sizeof(int));
	int *right=(int *)malloc((n2+1)*sizeof(int));
	int i,j=0,k;

	for (i=0; i<n1; i++)
    {
		*(left+i)=*(a+s+i);
	}

    *(left+n1)=1000000;
	for (i=0; i<n2; i++)
    {
		*(right+i)=*(a+m+i+1);
	}
	*(right+n2)=1000000;
	i=0;

	for (k=s; k<=e; k++)
    {
		if(left[i]<=right[j])
        {
			a[k]=left[i];
			i++;
		}
		else
        {
			a[k]=right[j];
			j++;
		}
	}
	free(left);
	free(right);
}

void merge_sort(int a[], int s, int e)
{
    int middle;
    if( e>s )
    {
        middle = ( s + e ) / 2;
        merge_sort(a, s, middle);
        merge_sort(a, middle+1, e);
        merge(a, s, middle, e);
    }
}

void radix_sort(int a[], int len)
{

}

void print(int a[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        printf("%-5d", a[i]);
    }
    printf("\n");
}

void rand_number(int a[], int len)
{
    int i;
    srand( time(NULL) );
    for(i=0; i<len; i++)
    {
        a[i] = rand()%1000;
    }
}

int main()
{
    int a[10];

    rand_number(a, 10);
    printf("插入排序序列:");
    print(a, 10);
    insert_sort(a, 10);     //插入排序
    printf("插入排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("希尔排序序列:");
    print(a, 10);
    shell_sort(a, 10);          //希尔排序
    printf("希尔排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("冒泡排序序列:");
    print(a, 10);
    bubble_sort(a, 10);         //冒泡排序
    printf("冒泡排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("快速排序序列:");
    print(a, 10);
    quick_sort(a, 0, 9);        //快速排序
    printf("快速排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("选择排序序列:");
    print(a, 10);
    select_sort(a, 10);        //选择排序
    printf("选择排序结果:");
    print(a, 10);
    printf("\n");


    rand_number(a, 10);
    printf("堆排序序列:");
    print(a, 10);
    creat_heap(a, 10);
    heap_sort(a, 10);        //堆排序
    printf("堆排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("归并排序序列:");
    print(a, 10);
    merge_sort(a, 0, 9);        //归并排序
    printf("归并排序结果:");
    print(a, 10);
    printf("\n");

    rand_number(a, 10);
    printf("基数排序序列:");
    print(a, 10);
    radix_sort(a, 10);        //基数排序
    printf("基数排序结果:");
    print(a, 10);
    printf("\n");

    return 0;
}
