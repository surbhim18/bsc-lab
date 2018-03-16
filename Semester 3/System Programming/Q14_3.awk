BEGIN{ 
printf "\nSorting - SELECTION\n"
count=0
}

{
	line[NR] = $0
	no[NR] = $1
	count++
}

END{
	for(i=1;i<count;i++)
	{
		minPos = i;

		for(j=i+1; j<=count; j++)
		{
			if(no[j] < no[minPos])
			{	minPos = j;  }
		}
		
		temp = line[i]
		tempNo = no[i]
		line[i] = line[minPos]
		no[i] = no[minPos]
		line[minPos] = temp
		no[minPos] = tempNo		
	}	


	for(i=1;i<=count;i++)
		printf "%s\n",line[i]
}
