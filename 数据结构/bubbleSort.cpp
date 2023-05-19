/*
冒泡排序
*/

/*
遍历若干次要排序的数组，每次遍历时会从前往后依次比较相邻的两个数大小
如果这两个数的顺序不符合要求则交换他们的位置，每次遍历都可以将一个遍历的范围中最值放到数组最后
时间复杂度：O（N^2)
稳定算法
*/

/**
 * @brief 不断地比较相邻的两个数据的大小，根据大小进行排序，如果顺序不对则交换彼此位置。
 * 
 * @param arr 
 * @param n 
 */

//递增顺序
void bubble(int arr[], int n)
{
    bool flag = false;
    for (int i = n-1; i > 0; ++i)   //循环次数，n个数，需要遍历 n-1 次
    {
        for (int j = 0; j < i; ++j){
            if (arr[j] > arr[i+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }

        if (flag){
            break;
        }
    }
}