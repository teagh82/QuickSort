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
    int low = left;  	// left�� pivot
    int high = right;
	int mid = left+right/2;
    int pivot = list[mid]; 	// �ǹ� ���� 
	printf("PIVOT = %d\n", pivot);

    while(low < high ) {		// low�� high�� �������� �ʴ� �� �ݺ� 
		for ( ; low <=right && list[low] < pivot ; low++) ; //low����
		for ( ; high>=left && list[high] > pivot ; high--) ; //high����
		if( low < high ) {		// ���õ� �� ���ڵ� ��ȯ 
			printf("[SWAP] %d %d\n", list[low], list[high]);
			SWAP(list[low],list[high],tmp);
		}
    } 
	if(pivot == list[mid]){
		SWAP(list[mid],list[high],tmp); // high�� �ǹ� �׸� ��ȯ 
		printf("[SWAP] %d %d\n", list[mid], list[high]);
	}
    
	c++;
	printf("PASS %d : ", c);
	for( int i=0 ; i<n ; i++ )
       printf("%3d", list[i]);
	printf("\n\n");
    return high;
}

// �� ���� : �迭�� left ~ right �׸���� ������������ �����ϴ� �Լ�
void quick_sort ( int list[], int left, int right, int n ) 
{ 
    int q;
    if( left<right ){ // low,high������Ű��swap, ������ pivot ��ȯ
	q = partition(list,left,right, n); 
	quick_sort (list, left, q-1, n);    // q�� ó���� pivot
	quick_sort (list, q+1, right, n);
    }
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void main()
{
	int list[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7 };
	printArray( list, 9, "Original" );	// ���� �� �迭 ��� 
	printf("\n");
	quick_sort( list, 0, 8, 9); 		// �� ���� ���� 
	printArray( list, 9, "Quick Data" );	// ���� �� �迭 ��� 

	system("pause");
}