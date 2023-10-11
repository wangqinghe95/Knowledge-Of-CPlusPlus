/*
归并排序：先递归分解数组将数组分成若干个子数组，然后再对子数组进行排序，合并，最终完成对整个数组的排序；
时间复杂度：O（NlogN）
稳定性：稳定
*/

void merge_sort(int arr[], int n)
{
    int *tmp = new int[n*sizeof(int)];
    msort(arr, tmp, 0, n-1);
    delete tmp;
}

void msort(int arr[], int *tmp, int start, int end)
{
    if (start < end){
        int middle = (start + end) / 2;
        msort(arr, tmp, start, middle);
        msort(arr, tmp, middle + 1, end);
        merge(arr, tmp, start, middle, end);
    }
}

void merge(int arr[], int *tmp, int start, int middle, int end)
{
    int l = start;
    int s = start;
    int r = middle;
    while (l <= middle && r <= end)
    {
        if (arr[l] <= arr[r]){
            tmp[s++] = tmp[l++];
        }
        else{
            tmp[s++] = tmp[r++];
        }
    }

    while (l <= middle)
    {
        tmp[s++] = tmp[l++];
    }

    while (r <= end)
    {
        tmp[s++] = tmp[r++];
    }

    for (; start <= end; start++){
        arr[start] = tmp[start];
    }
}
