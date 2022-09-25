#include <stdio.h>
int array_one[50][50];
int array_two[50][50];
int count=0;
int sum_of_one=0;
int i,j,row,col;
int generation;
int funcofonecounter(int,int);
int condition_for_one();
int condition_for_zero();
int logic_recursive_call(int);

int main()
{
    FILE *file1,*file2;

    int iteration,c=1,s=1;
    file1=fopen("text Input.txt","a");
    file2=fopen("text Output.txt","a");
    fprintf(file1,"\t\t\t\tWELCOME TO GAME OF LIFE\n");
    fprintf(file2,"\t\t\t\tWELCOME TO GAME OF LIFE\n");
    printf("\t\t\t\tWELCOME TO GAME OF LIFE\n");
    for(i=0;i<80;i++)
    {
        fprintf(file1,"-");
        fprintf(file2,"-");
        printf("-");
    }

    printf("\nGrid Size (Enter 0 0 for end) : ");
    scanf("%d %d",&row,&col);
    fprintf(file1,"\nGrid Size for %d : %d X %d \n\n",c,row,col);
    while(row != 0 && col != 0){

        printf("Enter no.of iterations: ");
        scanf("%d",&iteration);
        fprintf(file1,"\nIterations for %d : %d\n",s++,iteration);
        fprintf(file1,"Generations : \n");

        generation=0;
        printf("Enter Generations ('0' for die or '1' for alive) :\n",generation);
        for(i=0; i<row; i++)
        {
            printf("\n");
            fprintf(file1,"\n");
            for(j=0; j<col; j++)
            {
                scanf("%d",&array_one[i][j]);
                fprintf(file1,"%d  ",array_one[i][j]);
            }
        }
        printf("\n");
        fprintf(file1,"\n");

        logic_recursive_call(iteration);

        printf("\nGrid Size (Enter 0 0 for end) : ");
        scanf("%d %d",&row,&col);
        fprintf(file1,"\nGrid Size for %d : %d X %d \n\n",c++,row,col);
    }
        fclose(file1);
        fclose(file2);
}
int funcofonecounter(i,j)
{
    int k;
    int n;

    for( k=i-1; k<=i+1; k++)
    {
        if((k>=0)&&(k<=row))
        {
            for( n=j-1; n<=j+1; n++)

                if((n>=0)&&(n<=col))
                {
                    if((array_one[k][n]==1)&&(!((i==k)&&(j==n))))
                    {
                        count=count+1;
                    }
                }
            }
        }

    return count;
}
int condition_for_one()
{
    sum_of_one=funcofonecounter(i,j);


    if((sum_of_one<2)||(sum_of_one>3))
    {
        array_two[i][j]=0;
    }
    else
    {
        array_two[i][j]= array_one[i][j];
    }
    count=0;
    return 0;
}
int condition_for_zero()
{
    sum_of_one=funcofonecounter(i,j);
    if(sum_of_one==3)
        array_two[i][j]=1;
    else
    {
        array_two[i][j]= array_one[i][j];
    }

    count=0;
    return 0;
}
int logic_recursive_call(int x)
{
    FILE *file2;
    file2=fopen("text Output.txt","a");
    if(x!=0)
    {
        logic_recursive_call(x-1);
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                if(array_one[i][j]==1)
                {
                    condition_for_one();
                }
                else
                {
                    condition_for_zero();
                }
            }
        }


        generation++;

        printf("Generation %d:",generation);


        fprintf(file2,"\nGeneration %d:",generation);
        for(i=0; i<row; i++)
        {
            printf("\n");
            fprintf(file2,"\n");
            for(j=0; j<col; j++)
            {
                printf("%d ",array_two[i][j]);
                fprintf(file2,"%d ",array_two[i][j]);
            }
        }

        printf("\n");
        fprintf(file2,"\n");
        for(i=0; i<row; i++)
        {
            for(j=0; j<col; j++)
            {
                array_one[i][j]=array_two[i][j];
            }
        }

        return 0;
    }
    else
    {
        return 0;
    }
}
