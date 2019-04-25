#include<iostream>
int countBST(int count){
	int sum=0;
	for (int i = 0; i < count; i++)
		sum += countBST(count-i)*countBST(i-1);
	return(sum);
}
int main()
{
  int temp;
	printf("Enter number of nodes");
	scanf("%d",&temp );
	printf("%d is number of tress possible",countBST(temp));
	return 0;
}
