#include<stdio.h>
//#include<conio.h>
int rowmin(int ar[4][4],int rm[4][4]);
int colmin(int ar[4][4],int rm[4][4]);
int main()
{
	int m,x,totalr,reducedmatrix[4][4],reducedmatrix1[4][4],i,j,save_rm[4][4],mab,cost[3],k,first_rm[4][4],counter=0,min=9999/* min initialization for selecting min cost*/,select_node=0;
	int ar[4][4]={{999,10,15,20}, // array
	             {5,999,9,10 },
				 {6,13,999,12},
				 {8,8,9,999}};
				 totalr=rowmin(ar,reducedmatrix); //calling row min 
				 printf("\n\n total = %d\n\n",totalr); //printing cost after column reducion in matrix
				 
				 for(i=0;i<3;i++)
				 {
				 	
				 	for(j=0;j<=3;j++)
				 	{
				 	save_rm[i][j]=reducedmatrix[i][j]; //copying reduced matrix in saved reduced matrix 
					 //printf("%d ",save_rm[i][j]);
					 }
					 printf("\n");
					 
				}
				 
				 for(m=0; m<3; m++)
				 {
			      counter = 0;
				 min=9999;
				 for(k=1;k<=3-m /*since every time node will be reduced (after selection)*/;k++)
				 {
				 	mab=save_rm[m][k+m]; //value of mab is equal to saved reduced matrix at position 0 , k
				    if(mab==999)
					{mab=0;
					}
					//printf("mab %d %d  %d",mab,select_node,k+m);	
					 reducedmatrix[k][select_node]=999; // making reduced matrix at position k ,0 as infinity
				 	counter++;
				 	for(i=0;i<=3;i++)
				 {
				 	
				 	for(j=0;j<=3;j++)
					 {
					 
					 if(i==select_node || j==k) //if i== 0 and j==value of k then reduced matrix at position i,j is infinity
					 {
					 	reducedmatrix[i][j]=999; //making reduced matrix at i , j as infinity
					 }
					 if(counter==1){
					 first_rm[i][j]=reducedmatrix[i][j];
					 }//printf("%d ", first_rm[i][j]);
					 }
					 printf("\n");
					 }
					 
					 x=mab;
					 cost[k]=rowmin(reducedmatrix,reducedmatrix1);  //calculating cost of row minimized matrix
					 cost[k]=totalr+cost[k]+x;                 //calculating total cost of reduced matrix (formula ; cost = total cost of reduced matrix +cost(of previous martrix) +  value of mab )
					 printf("cost  =   %d	\n",cost[k]);    // printing cost
					 if(min > cost[k])
					 {min=cost[k];
					 select_node=k;
					 } 
			    }
			    printf("min cost is %d ",min);
			    printf("\n");
			    printf("selected node is %d ",select_node);
			    for(i=0;i<=3;i++){
			    	
			    	for(j=0;j<=3;j++){
			    		save_rm[i][j]=first_rm[i][j];
					}
				}
				
			}
			 
			} 
				 //calculating min in row 
				 int rowmin(int ar[4][4],int reducedmatrix[4][4])
				 {
				 int rowreduction=0,totalreduction;
				 	int min[4]={999,999,999,999},i,j;
				 	for( i=0;i<4;i++)
				 	{
				 		for( j=0;j<4;j++)
				 		{
				 			
				 		if(min[i]>ar[i][j])
				 		{
						 min[i]=ar[i][j];
						 } 
						 
						 
						 }
						 if(min[i]==999)
						 {
						 min[i]=0;
						 }
						 rowreduction=rowreduction+min[i]; //adding row min
				 	
				 }
				 for(i=0;i<4;i++) // for loop for subtracting min value from each row value 
				 {
				 	for(j=0;j<4;j++)
				 	{ 
					 if(ar[i][j]!=999)
					 {
					 
				 		ar[i][j]=ar[i][j]-min[i];
				 		
					 } 
					// printf("%d	",ar[i][j]);
					 }
					 //printf("\n");
				}
					for(i=0;i<4;i++) 
				 {
				 	for(j=0;j<4;j++)
				 	{
					reducedmatrix[i][j]=ar[i][j];
					 //printf("%d	",ar[i][j]);
				 		
					 }
					 //printf("\n");
 
			}
				 totalreduction=colmin(ar,reducedmatrix);
				 totalreduction=totalreduction+rowreduction; //
				 return totalreduction;
				 }
				 
			
			
			//calculating min in column
			
			
			int colmin(int ar[4][4],int reducedmatrix[4][4])
				 {
				 	int colreduction=0;
				 	int min[4]={999,999,999,999},i,j;
				 	for( i=0;i<4;i++)  //finding min in row matrix
				 	{
				 		for( j=0;j<4;j++)
				 		{
				 		if(min[i]>ar[j][i]) //checking if min is greater than value at that particular instant
				 		{
						 min[i]=ar[j][i]; //min value found and stored
						 }
						 
						 }
                           if(min[i]==999){min[i]=0;}
						 colreduction=colreduction+min[i]; //adding total min value in column min matrix
				 	
				 }
				 for(i=0;i<4;i++) // for loop for subtracting min value from each column value 
				 {
				 	for(j=0;j<4;j++)
				 	{ if(ar[j][i]!=999) //checking if column value is 
					 {
					 
				 		ar[j][i]=ar[j][i]-min[i]; //subtracting value at array i,j with min value in a column
				 		
					 } 
		
					 }
					 
				 }
				for(i=0;i<4;i++) 
				 {
				 	for(j=0;j<4;j++)
				 	{
					reducedmatrix[i][j]=ar[i][j];
					 //printf("%d	",ar[i][j]);
				 		
					 }
					 printf("\n");
 
			}
			return colreduction; //returning value of column reduction 
		}
				

