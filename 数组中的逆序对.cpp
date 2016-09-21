/* 题目 
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007 
*/

void mergeSort(vector<int>& nums, int left, int right, vector<int> &count){
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergeSort(nums,left,mid,count);
    mergeSort(nums, mid + 1, right, count);
    int index1 = left, index2 = mid + 1,index=0;
    vector<int> sortedNum(right - left + 1), tempCount(right - left + 1);
    while (index1 <= mid || index2 <= right){
        if (index1 <= mid && index2 <= right){
            if (nums[index1] > nums[index2]){
                sortedNum[index] = nums[index1];
                tempCount[index] = count[index1] + right - index2 + 1;
                index1++;
            }
            else if (nums[index1] == nums[index2]){
                sortedNum[index] = nums[index1];
                tempCount[index] = count[index1] + right - index2;
                index1++;
            }
            else{
                sortedNum[index] = nums[index2];
                tempCount[index] = count[index2];
                index2++;
            }
        }
        else if (index1 <= mid){
            sortedNum[index] = nums[index1];
            tempCount[index] = count[index1];
            index1++;
        }
        else{
            sortedNum[index] = nums[index2];
            tempCount[index] = count[index2];
            index2++;
        }
        index++;
    }
    for (int i = 0; i < right - left + 1; i++){
        nums[left + i] = sortedNum[i];
        count[left + i] = tempCount[i];
    }
}

int InversePairs(vector<int> data) {
    vector<int> count(data.size(),0);
    mergeSort(data,0,data.size()-1,count);
    int res = 0;
    for (int i = 0; i < data.size(); i++){
        res += count[i];
        if (res > 1000000007)
            res %= 1000000007;
    }
    return res;
}
