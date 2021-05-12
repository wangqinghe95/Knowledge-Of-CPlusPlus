/*
快速排序：每次选择一个元素并且将整个数组以选择的元素为基点分成两个部分。小于该元素的放在左边，大于该元素的放在右边；
时间复杂度：O（NlogN）
空间复杂度：O（logN）
*/

//代码实现
void quickSort(int arr[], int n)
{
    qSort(arr, 0, n-1);
}

void qSort(int arr[], int low, int high)
{
    if (low < high){
        int pivotpos = partition(arr, low, high);
        qSort(arr, 0, pivotpos-1);
        qSort(arr, pivotpos+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int tmp = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] > tmp)
        {
            high--;
        }

        arr[low] = arr[high];
        
        while (low < high && arr[low] < tmp)
        {
            low++;
        }
        
        arr[high] = arr[low];
    }

    arr[low] = tmp;
    return low;    
}

/*
快排中最关键的是分区函数（partition），而分区函数最核心的是选择比较的元素
通常根据算法不同，被比较的函数有以下几种选择方法：
1. 永远选择第一个元素
2. 永远选择第二个元素
3. 随机选择
4. 取中间值
*/