#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))

int c = 0;
int partition ( int list[], int left, int right, int n ) 
{
	printf("[left= %d, right= %d]   ", left, right);
	for( int i=0 ; i<left ; i++ )
       printf("%2d", list[i]);
	printf("[");
	for( int i=left ; i<=right ; i++ )
       printf("%2d", list[i]);
	printf(" ]");
	for( int i=right+1 ; i<n ; i++ )
       printf("%2d", list[i]);
	printf("\n");

    int tmp;
    int low = left+1;  	// left는 pivot
    int high = right;
    int pivot = list[left]; 	// 피벗 설정 
	printf("PIVOT = %d\n", pivot);

    while(low <= high ) {		// low와 high가 역전되지 않는 한 반복 
		for ( ; low <=right && list[low] < pivot ; low++) ; //low증가
		for ( ; high>=left && list[high]> pivot ; high--) ; //high감소
		if( low < high ) {		// 선택된 두 레코드 교환 
			printf("[SWAP] %d %d\n", list[low], list[high]);
			SWAP(list[low],list[high],tmp);
		}
    } 
	SWAP(list[left],list[high],tmp); // high와 피벗 항목 교환 
	printf("[SWAP] %d %d\n", list[left], list[high]);
	c++;
	printf("PASS %d : ", c);
	for( int i=0 ; i<n ; i++ )
       printf("%3d", list[i]);
	printf("\n\n");
    return high;
}

// 퀵 정렬 : 배열의 left ~ right 항목들을 오름차순으로 정렬하는 함수
void quick_sort ( int list[], int left, int right, int n ) 
{ 
    int q;
    if( left<right ){ // low,high증가시키며swap, 마지막 pivot 교환
	q = partition(list,left,right, n); 
	quick_sort (list, left, q-1, n);    // q는 처리한 pivot
	quick_sort (list, q+1, right, n);
    }
}

// 배열을 화면에 보기 좋게 출력하는 함수. 디폴트 매개변수 사용
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void main()
{
	int list[8] = { 71, 49, 92, 55, 38, 82, 72, 53 };
	printArray( list, 8, "Original" );	// 정렬 전 배열 출력 
	printf("\n");
	quick_sort( list, 0, 7, 8); 		// 퀵 정렬 실행 
	printArray( list, 8, "Quick Data" );	// 정렬 후 배열 출력 

	system("pause");
}