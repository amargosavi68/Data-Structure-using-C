//#include<stdio.h>
//
//int BinarySearch(int *a, int l, int h, int key)
//{
//	printf("\nFirst: %d",*(a+l));
//	int mid;
//	if(l == h){
//		if(*(a+l) == key){
//			return 1;
//		}
//		else{
//			return 0;
//		}
//	}
//	else{
//		mid = (l+h)/2;
//		printf("\nMid: %d",*(a+mid));
//		printf("\nLast: %d",*(a+h));
//		if(*(a+mid) == key){
//			return 1;
//		}
//		else if(*(a+mid) <= key){
//			return BinarySearch(a,mid+1,h,key);
//		}
//		else{
//			return BinarySearch(a,l,mid-1,key);
//		}
//	}
//}
//
//void main()
//{
//	int b[100],i, *a;
//	a = b;
//	printf("\nEnter 5 elements: ");
//	for(i = 0; i < 5; i++){
//		scanf("%d",&*(a+i));
//	}
//	printf("\nElements are: \n");
//	for(i = 0; i < 5; i++){
//		printf("%d  ",*(a+i));
//	}
//	if(BinarySearch(a,0,4,4) == 1)
//	{
//		printf("\nElement is found..");
//	}
//	else
//	{
//		printf("\nElement is not found..");
//	}
//}
