/*
插入排序:每一步将一个待排序的数据插入到前面已经拍好序的有序序列中，直到插完所有元素为止；
时间复杂度：O(N^2)
稳定性：稳定算法
*/

void insert_sort(int arr[], int n){
    for (int i = 1; i < n; ++i){
        int j = i;
        int tmp = arr[i];
        for (; j > 0 && arr[j-1] > tmp; j--){  //如果前一个元素大于后一个元素就把前一个元素的位置放到后一个位置上去
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}