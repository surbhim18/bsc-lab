BEGIN{ 
printf "\nSorting - INSERTION\n"
count=0
}

{
	line[NR] = $0
	no[NR] = $1
	count++
}

END{
	for(i=2;i<=count;i++)
	{
		j=i-1;
		temp = line[i];
		tempNo = no[i];		

		while(j>=1 && tempNo < no[j])
		{
			line[j+1] = line[j]
			no[j+1] = no[j]			

			j--;
			
		}
		
		line[j+1] = temp;
	}	


	for(i=1;i<=count;i++)
		printf "%s\n",line[i]
}
