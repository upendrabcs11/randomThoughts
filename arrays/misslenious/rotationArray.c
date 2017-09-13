#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int getPivotIndex(int *arr,int min,int max){
    if(min > max)
        return -1;
    if(min == max)
        return min;
    
   int mid = (min + max)/2; 
   if(arr[mid] > arr[mid+1])
        return mid;
   if(arr[min] < arr[mid])
       return getPivotIndex(arr,mid+1, max);
   else
       return getPivotIndex(arr,min, mid-1);
}

bool checkPairExistWithGivenSum(int *arr,int n,int k){ 
    int pivot = getPivotIndex(arr,0, n-1);
    printf("%d ",pivot);
    int min = pivot+1;
    int max = pivot;
    while(min != max){
        int sum = arr[min] + arr[max];
      if(sum == k)
          return true;
      if(sum < k){
          min = (min + 1) % n;
      }else{
            max = (max -1 + n) % n ;
        }
    }
    return false;
}

int getMaxRotatedIndexMValue(int *arr,int n){
	int arrSum = 0,curSum = 0;
	for(int i=0;i < n ; i++){
		arrSum += arr[i];
		curSum += i*arr[i];
	}
	int k = 0 , maxSum = curSum;
	while(++k < n){
		curSum = curSum + arrSum - n*arr[n-k] ;
		if( maxSum < curSum)
			maxSum = curSum;
	}
    return maxSum;
}

int main(){
    int n,k; 
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i = 0; i < n; i++){
       scanf("%d",&arr[i]);
    }
    if(checkPairExistWithGivenSum(arr,n,k))
        printf("motki ko pairs element mil gaya \n");
    else
        printf("motki ko pairs element nahi mila \n");
    return 0;
}
