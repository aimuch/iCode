# 排序

## 冒泡排序

**向上冒泡**
```c
// from tail to head
void BubbleSort(int array[], int len) // O(n*n)
{
    int i = 0;
    int j = 0;
    int temp;
    int exchange = 1;
    
    for(i=0; (i<len) && exchange; i++)
    {
        exchange = 0;
        for(j=len-1; j>i; j--)
        {
            if( array[j] < array[j-1] )
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                exchange = 1;
            }
        }
    }
}
```

**向下冒泡**
```c
// from head to tail
void BubbleSort_1(int* array, int n)
{
    int temp;
    for(int j=0; j<n-1; j++)
    {
        for(int i=0; i<n-j; i++)
        {
            if( array[i]>array[i+1] )
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
    }
}
```