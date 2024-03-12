#include<stdio.h>
int main(){
    int matrix1[3][3];
    int matrix2[3][3];
    int temp[3][3]={0,0,0,0,0,0,0,0,0};
    int choice,ch;
    printf("\nEnter the values for first Matrix: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d,",&matrix1[i][j]);
        }
    }
    printf("\nEnter the values for Second Matrix: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d,",&matrix2[i][j]);
        }
    }
    printf("Enter Your Choice of operation on matrix : \n");
    printf("1. Addition\n2. Transpose\n3. Multiplication\n->");
    scanf("%d",&choice);

    switch(choice){

        case 1:
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    temp[i][j]=matrix1[i][j]+matrix2[i][j];
                }
            }
            printf("Matrix After addition:\n");
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",temp[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            printf("For which matrix You want transpose ,1 or 2: ");
            scanf("%d",&ch);
            switch(ch){

                case 1:

                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            temp[i][j]=matrix1[j][i];
                        }
                    }
                    printf("Matrix Before Transpose:\n");
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            printf("%d ",matrix1[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Matrix After Transpose:\n");
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            printf("%d ",temp[i][j]);
                        }
                        printf("\n");
                    }
                    break;

                case 2:

                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            temp[i][j]=matrix2[j][i];
                        }
                    }
                    printf("Matrix before Transpose :\n");
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            printf("%d ",matrix2[i][j]);
                        }
                        printf("\n");
                    }
                    printf("Matrix After Transpose:\n");
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            printf("%d ",temp[i][j]);
                        }
                        printf("\n");
                    }
                    break;

            }  
        case 3:
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        temp[i][j]= temp[i][j]+(matrix1[i][k]*matrix2[k][j]);
                    }
                }
            }
            printf("Result of Matrix multiplication:\n");
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",temp[i][j]);
                }
                printf("\n");
            }
        default:
            printf("\nWrong Choice....");

    }
           
}




