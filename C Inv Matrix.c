#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	float t[3][3],q[3][3],s[3][3],v[3],w[3];
	int a,b,i,j,x,y,d,p;
	float z=0;
	//filling out the matrix
	printf("this program will return the inv Matrix\nPlease fill out the Matrix\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("[%d,%d]\t",i+1,j+1);
			scanf("%f",&t[i][j]);
		}
		printf("\n");
	}
	//for systems
/*	printf("Please enter the results =:\n");
	for(j=0;j<3;j++)
		{
			printf("[%d]\t",j+1);
			scanf("%f",&w[j]);
		}
		printf("\n");
*/
	//calculating the determinant
	for(i=0;i<3;i++)
		{
			v[i]=t[0][i];
		}
	
		i=-1;d=0;
		for(j=0;j<3;j++)
		{	a=0,b=0,i++;
			for(x=1;x<3;x++)
			{
				for(y=0;y<3;y++)
				{
					if(!(j==y) )
					{
						s[a][b]=t[x][y];
						b++;
						if(b==2){ b=0,a++;}
					}
				}
			}
			if(i==1)
			{
				p=-1*(v[i]*((s[0][0]*s[1][1])-(s[0][1]*s[1][0])));
			}
			else
			{
				p=v[i]*((s[0][0]*s[1][1])-(s[0][1]*s[1][0]));
			}
				d=d+p;
		}
		
		printf("\nthe Det= %d\n",d);
		//calculating the cofactots
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				a=0,b=0;
				for(x=0;x<3;x++)
				{
					for(y=0;y<3;y++)
					{
						if(!(j==y) && !(x==i) )
						{
						s[a][b]=t[x][y];
						b++;
						if(b==2){ b=0,a++; }
						}
					}
				}
				q[i][j]=(s[0][0]*s[1][1])-(s[0][1]*s[1][0]);
			}
		}
			

	a=0;	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			a=(i+1)+(j+1);
			if ( !(a%2 == 0) )
			{
				q[i][j] = (q[i][j]) * (-1);
			}
		}
		printf("\n");
	}
	
	printf("the Cofactors are: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("[%.0f]\t",q[i][j]);
		}
		printf("\n");
	}
	
	printf("the matrix of inv Cofactors: \n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			t[j][i]=q[i][j];
		}
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			printf("[%.0f]\t",t[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThe inv Matrix is\n");
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			p=t[i][j]/d;
			printf(" %.0f/%d   \t\t",t[i][j],d);			
		}
		printf("\n");
	}
	printf("\nwhich is;\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)	
		{
			q[i][j]=t[i][j]/d;
			z=t[i][j]/d;
		/*	if( !(z%2==0)) { printf("[%.2f/%d]\t",t[i][j],d);}	
			else { printf("[%.2f]\t",z);}
		*/	
			printf(" %.2f   \t\t",z);			
		}
		printf("\n");
	}
//  the last result of the system
/*	for(i=0;i<3;i++)
	{z=0;
		for(j=0;j<3;j++)
		{
			z=z+(q[i][j]*w[j]);
		}
		printf("\n%.2f\n",z);
	}
*/
	return 0;
}