#include<stdio.h>
	
int main()
{
	int check = 0,tempstat=0, n,j=0,i=0,dist[100][100],tc=0,tci=0,tempmin=0,tcmin=0,x=0,k=0,minpop=0,minpopi=0,tempmax=0,l=0,mindist=0,count=0;
	float stats[100][100],air[100][100],humid[100][100],stationtemp=0,avgcitytemp=0,result[100][100],countmax=0,q4[100][100],q3[100][100],heatin=0;
	printf("\n Enter the number of stations\n");
	scanf("%d",&n);
	printf("\n Enter the following statistics of each station: \n");
	while(i<100)
	{
		j=0;
		while(j<100)
		{
			if(i<n)
			{	
				if(j==0)
				{
					while(check==0)
					{
						printf("\n Enter sky view factor: \n");
						scanf("%f",&stats[i][j]);
						if(stats[i][j]> 0.9 || stats[i][j]< 0.1)
						{
							printf("\n Invalid Entry. Please input again\n\n");
						}
						else
						{
							check = 1;
						}
					}
					check=0;
				}
						
				if(j==1)
				{
					printf("\n Enter Vegetation density ratio: \n");
					scanf("%f",&stats[i][j]);
				}
				if(j==2)
				{
					printf("\n Enter Population Density: \n");
					scanf("%f",&stats[i][j]);
				}
				if(j==3)
				{
					while(check==0)
					{
						printf("\n Enter Pervious Surface Fraction: \n");
						scanf("%f",&stats[i][j]);
						if(stats[i][j]> 15 || stats[i][j]< 0)
						{
							printf("\n Invalid Entry. Please input again\n\n");
						}
						else
						{
							check = 1;
						}
					}
					check=0;
				}
				if(j==4)
				{
					while(check==0)
					{
						printf("\n Enter Imervious Surface Fraction: \n");
						scanf("%f",&stats[i][j]);
						if(stats[i][j]> 15 || stats[i][j]< 0)
						{
							printf("\n Invalid Entry. Please input again\n\n");
						}
						else
						{
							check = 1;
						}
					}
					check=0;
				}
				if(j==5)
				{
					printf("\n Enter Station status (0 if Rural, 1 if Urban): \n");
					scanf("%f",&stats[i][j]);
				}
			}
				if(i>=n || j>=6)
				{
					stats[i][j] = 0;
				}
				j++;
			
		}
		i++;
	}	
	i=0;
    while(i<100)
	{
		j=0;
		while(j<100)
		{
			if(j>i && i<n && j<n)
			{
				printf("\n Enter the distance between station %d and station %d\n",i+1,j+1);
				scanf("%d",&dist[i][j]);
				dist[j][i]=dist[i][j];
			}
			if(i==j)
			{
				dist[i][i] = 0;
			}
			if(i>=n || j>=n)
			{
				dist[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	i=0;
	j=0;
	printf("\n Enter Air Temperature details");
	while(i<100)
	{
		j=0;
		while(j<100)
		{
			if(i<n)
			{
				if(j<30)
				{
					printf("\n Station %d Day %d\n",i+1,j+1);
					scanf(" %f",&air[i][j]);
					stationtemp = stationtemp + air[i][j];
				}
			}
			if(i>=n || j>=n)
			{
				air[i][j]=0;
			}
			j++;
		}
		i++;
	}
	avgcitytemp=stationtemp/(float)(n*30);
	i=0;
	j=0;
	printf("\n Enter Relative Humidity details");
	while(i<100)
	{
		j=0;
		while(j<100)
		{
			if(i<n)
			{
				if(j<30)
				{
					printf("\n Station %d Day %d\n",i+1,j+1);
					scanf(" %f",&humid[i][j]);
				}
			}
			if(i>=n || j>=n)
			{
				humid[i][j]=0;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	printf("\n Heat degree days: ");
	i=0;
	j=0;
	while(i<n)
	{
		j=0;
		while(j<30)
		{
		 	if(air[i][j]>avgcitytemp)
		 	{
		 		result[i][0]++;
		 	}
		 	j++;
		 }
		 i++;
	}
	i=0;
	j=0;
	while(i<n)
	{
		if(result[i][0]>countmax)
		{
			countmax=result[i][0];
		}
		i++;
	}
	printf("\n Station(s) with highest number of heat degree days: ");
	while(i<n)
	{
		if(result[i][0] == countmax)
		{
			printf("\n Station %d",i);
		}
	}
	i=0;
	j=0;
	printf("\n\n Enter the station whose thermally comfortable days are to be checked: \n");
	scanf(" %d",&tc);
	mindist = dist[tc-1][1];
	if(stats[tc-1][5] == 0)
	{
		printf("\n City is rural. Enter an urban city");
	}
	else
	{
		while(i<n)
		{
			if(mindist>dist[tc-1][i] && dist[tc-1][i] !=0)
			{
				mindist = dist[tc-1][i];
			}
			i++;
		}
		tci = i;
		i=0;
		while(i<n)
		{
			if(mindist == dist[tc-1][i] && stats[i][3]>stats[tci][3])
			{
				tci = i;
			}
			i++;
		}
	}
	i=0;
	j=0;
	while(i<30)
	{
		if(air[tc-1][i]<air[tci-1][i])
		{
			tempmin=air[tci-1][i]-air[tc-1][i];
		}
		else
		{
			tempmin=air[tc-1][i]-air[tci-1][i];
		}
			
		if(tcmin>tempmin)
		{
			tcmin=tempmin;
		}
		i++;
	}
	while(i<30)
	{
		if(air[tc-1][i]<air[tci-1][i])
		{
			tempmin=air[tci-1][i]-air[tc-1][i];
		}
		else
		{
			tempmin=air[tc-1][i]-air[tci-1][i];
		}
		if(tcmin==tempmin)
		{
			printf("\n Day %d",i+1);
		}
		i++;
	}
	printf("\n List of stations according to decreasing vegetation density and their respectives dates with temperature more than average city temperature: \n");
	i=0;
	j=0;
	while(i<n)
	{
		q3[i][0] = i+1;
		q3[i][1] = stats[i][2];
		i++;
	}
	for(j=0;j<n-1;j++)
		{
			for(l=0;l<n-j-1;l++)
			{
				if(q3[j][1]<q3[j+1][1])
				{
					q3[j][1] = q3[j][1] + q3[j+1][1];
					q3[j+1][1]=	q3[j][1] - q3[j+1][1];
					q3[j][1]=q3[j][1] - q3[j+1][1];
			    	q3[j][0] = q3[j][0] + q3[j+1][0];
					q3[j+1][0]=	q3[j][0] - q3[j+1][0];
					q3[j][0]=q3[j][0] - q3[j+1][0]; 
				}
			}
		}
	i=0;
	j=0;
	while(i<n)
	{
		j=q3[i][0];
		printf("\n Station %d \n",j);
		j=0;
		while(j<30)
		{
		 	l=q3[i][0];
			if(air[l-1][j]>avgcitytemp)
		 	{
		 		printf("   Day %d",j+1);
		 	}
		 	j++;
		 }
		 i++;
	}		
	i=0;
	j=0;
	printf("\n\n Enter the value of k");
	scanf(" %d",&k);
	minpop=stats[0][2];
	while(i<n)
	{
		while(j<30)
		{
			if(tempmax<air[i][j])
			{
				tempmax = air[i][j];
				air[i][30] = tempmax;
			}
			j++;
		}
		i++;
	}
	j=0;
	x=0;
	while(x<=k)
	{
		count =0;
		i=0;
		while(i<n)
		{
			if(stats[i][2]<minpop && stats[i][2] !=0)
			{
				minpop = stats[i][2];
				minpopi=i;
			}
			i++;
		}
		i=0;
		j=0;
		while(i<n)
		{
			j=0;
			if(minpop == stats[i][2])
			{
				stats[i][2] = 0;
				q4[j][0] =i;
				q4[j][1]= air[i][30];
				count++;
				j++;
			}
			i++;
		}
		j=0;
		if (count>1)
		{
			for(j=0;j<count-1;j++)
			{
				for(l=0;l<count-j-1;l++)
				{
					if(q4[j][1]>q4[j+1][1])
					{
						q4[j][1] = q4[j][1] + q4[j+1][1];
						q4[j+1][1]=	q4[j][1] - q4[j+1][1];
						q4[j][1]=q4[j][1] - q4[j+1][1];
	    				q4[j][0] = q4[j][0] + q4[j+1][0];
						q4[j+1][0]=	q4[j][0] - q4[j+1][0];
						q4[j][0]=q4[j][0] - q4[j+1][0]; 
					}
				}
			}
		}
  		j=0;
		while(j<count && x+j+1<=k)
  		{	
    		tempstat=q4[j][0];
    		printf("\n Station %d ",tempstat);
   			j++;
  		}	
  		x=x+count;
	}
	i=0;
	j=0;
	while(i<n)
	{
		if(stats[i][5]==1)
		{
			j=0;
			printf("\n\n Station %d",i+1);
			mindist = dist[i][1];
			while(j<n)
			{
				if(mindist>dist[i][j])
				{
					mindist = dist[i][j];
					tci = j;
				}
				j++;
			}
			j=0;
			while(j<n)
			{
				if(mindist == dist[i][j] && stats[j][3]>stats[tci][3])
				{
					tci = j;
				}
				j++;
			}
			j=0;
			while(j<30)
			{
				if(air[i][j]>air[tci][j])
				{
					heatin = heatin + (air[i][j]-air[tci][j])/30;
				}
				if(air[i][j]<air[tci][j])
				{
					heatin = heatin + (air[tci][j]-air[i][j])/30;
				}
				j++;
			}
			printf("\n Heat intensity = %f",heatin);
		}
		i++;
	}
	
}
