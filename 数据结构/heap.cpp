/*
堆排序：
    1. 将待排序的序列构造成一个大顶堆，根据大顶堆性质，当前堆的根结点（堆顶）就是序列中最大的元素；
    2. 将堆顶元素和最后一个元素交换，再将剩下的结点重新构造成一个大顶堆；
    3. 重复上述步骤，每一次构建大顶堆都可以获取到一个最大值，将它放到尾部，就可以获取到一个有序序列了；
时间复杂度：O（NlogN）
稳定性：不稳定
*/

void heap_sort(int arr[], int n)
{
    if (n < 2){
        return;
    }

    for (int i = (n-2)/2; i >= 0; --i){
        percdown(arr, n, i);
    }

    for (int i = n-1; i > 0; --i){
        swap(arr[i], arr[0]);
        percdown(arr, i, 0);
    }
}

void percdown(int arr[], int n, int i)
{
    int child;
    int parent = i;
    for (; parent * 2 + 1 < n; parent = child){
        child = parent * 2 + 1;
        if (child + 1 < n && arr[child] < arr[child+1]){
            child = child + 1;  //右孩子存在且右孩子的值大于左孩子
        }

        if (arr[child] > arr[i]){       //如果孩子的值大于第 i 个值，就把孩子的值赋给父亲
            arr[parent] = arr[child];
        }
        else{
            break;
        }
    }

    arr[parent] = arr[i];
}