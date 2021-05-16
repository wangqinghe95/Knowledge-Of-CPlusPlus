/*
选择排序：每次从待排序的集合中选择最小（大）的元素放到已排序的序列末尾，直至排序结束；
时间复杂度：O(N^2);
稳定性：不稳定；
*/

void select_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++){
        int tmp = arr[i];
        int t = i;
        for (int j = i + 1; j < n; ++j){
            if (arr[j] < tmp){
                tmp = arr[j];
                t = j;
            }
        }

        arr[t] = arr[i];
        arr[i] = tmp;
    }
}