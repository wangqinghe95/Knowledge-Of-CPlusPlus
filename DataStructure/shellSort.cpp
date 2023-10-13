/*
希尔排序:
    1. 直接插入算法的高效版；
    2. 将待排序的数组元素按下标的一定增量分组，分为多个子序列
    3. 然后对各个子序列进行直接插入排序；
    4. 然后依次缩减增量再进行排序，直至增量为 1 时，进行最后一次直接插入排序；
时间复杂度：O(NlogN)
稳定性：不稳定算法
*/

//shell 增量
void shell_sort(int arr[], int n)
{
    for (int d = n / 2; d > 0; d /= 2){
        for (int i = d; i < n; i++){
            int tmp = arr[i];
            int j = i;
            for (; j >= d && arr[j-d] > tmp; j -= d){
                arr[j] = arr[j-d];
            }
            arr[j] = tmp;
        }
    }
}

//sedgewick 增量

void shell_sedgewick(int arr[], int n){
    int sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1 , 0};

    int si = 0;
    for ( ;sedgewick[si] >= n; si++){
        ;
    }
    for ( ; sedgewick[si] > 0; si++){
        int d = sedgewick[si];
        for (int i = d; i < n; i++){
            int tmp = arr[i];
            int j = i;
            for (; j >= d && arr[j-d] > tmp; j -= d){
                arr[j] = arr[j-d];
            }
            arr[j] = tmp;
        }
    }
}