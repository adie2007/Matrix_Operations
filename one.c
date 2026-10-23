//matrix addition, subtraction, multiplication and transpose
#include <stdio.h>
#define MAX 10

void Enter_Matrix(int matrix[MAX][MAX],int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("Enter element at index [%d][%d] : ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
}

void Display_Matrix(int matrix[MAX][MAX],int row,int col){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}

void Matrix_Addition(int A[MAX][MAX],int row,int col,int B[MAX][MAX],int Result[MAX][MAX]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			Result[i][j]=A[i][j]+B[i][j];
		}
	}
}

void Matrix_Subtraction(int A[MAX][MAX],int row,int col,int B[MAX][MAX],int Result[MAX][MAX]){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			Result[i][j]=A[i][j]-B[i][j];
		}
	}
}

void Matrix_Multiplication(int A[MAX][MAX],int r1,int c1,int B[MAX][MAX],int r2,int c2,int Result[MAX][MAX]){
	for(int i=0;i<r1;i++){
		for(int j=0;j<c2;j++){
			Result[i][j]=0;
			for(int k=0;k<c1;k++){
				Result[i][j]=Result[i][j]+(A[i][k]*B[k][j]);
			}
		}
	}
}

void Matrix_Transpose(int Matrix[MAX][MAX],int row,int col){
	int Transpose[MAX][MAX];
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			Transpose[i][j]=Matrix[j][i];
		}
	}
	Display_Matrix(Transpose,col,row);
}

int main(){
	int r1=0,c1=0,r2=0,c2=0,choice=0;
	int A[MAX][MAX],B[MAX][MAX],Sum[MAX][MAX],Difference[MAX][MAX],Product[MAX][MAX];

	//-------------------------------
	//Matrix A
	//-------------------------------
	
	printf("Enter the number of rows and columns in Matrix A (separated by space) : ");
	scanf("%d %d",&r1,&c1);
	if(r1>MAX || r2<=0 || c1>MAX || c1<=0 ){
		printf("\nSize should be less than 10 and greater than 0 !!\n");return 1;
	}
	printf("\nReading Matrix A : \n");
	Enter_Matrix(A,r1,c1);
	printf("\nDisplaying Matrix A : \n");
	Display_Matrix(A,r1,c1);


	//-------------------------------
	//matrix B
	//-------------------------------
	
	printf("\nEnter the number of rows and columns in Matrix B (separated by space) : ");
	scanf("%d %d",&r2,&c2);
	if(r2>MAX || c2>MAX){
		printf("Size should be less than 10 !!\n");return 1;
	}
	printf("\nReading Matrix B : \n");
	Enter_Matrix(B,r2,c2);
	printf("\nDisplaying Matrix B : \n");
	Display_Matrix(B,r2,c2);

	while(choice!=5){
		printf("\n1. Addition of Matrix A + B\n2. Subtraction of Matrix A - B\n3. Multiplication of Matrix A * B\n4. Transpose of Matrix A and B\n5. Quit\nChoose Operation to perform : ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("\nAddition of Matrix A + Matrix B : \n");
				if(r1!=r2 || c1!=c2)
					printf("Row and columm should be same for Addition\n");
				else{
					Matrix_Addition(A,r1,c1,B,Sum);
					Display_Matrix(Sum,r1,c1);
				}
				break;
			case 2:
				printf("\nSubtraction of Matrix A - Matrix B : \n");
				if(r1!=r2 || c1!=c2)
					printf("Row and columm should be same for Subtraction\n");
				else{
					Matrix_Subtraction(A,r1,c1,B,Difference);
					Display_Matrix(Difference,r1,c1);
				}
				break;
			case 3:
				printf("\nMultiplication of Matrix A * Matrix B : \n");
				if(c1!=r2)
					printf("Multiplication cannot be done since no. of column of first != no. row of second\n");
				else{
					Matrix_Multiplication(A,r1,c1,B,r2,c2,Product);
					Display_Matrix(Product,r1,c2);
				}
				break;
			case 4:
				printf("\nTranspose of Matrix A :\n");
				Matrix_Transpose(A,r1,c1);
				printf("\nTranspose of Matrix B :\n");
				Matrix_Transpose(B,r2,c2);
				break;
			case 5:
				printf("\nTerminating Program...\n");
				break;
			default:
				printf("\nINVALID CHOICE\n");
		}
	}
	return 0;
}
