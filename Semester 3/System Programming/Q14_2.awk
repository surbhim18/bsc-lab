BEGIN{ 
printf "\nSorting - BUBBLE\n"
count=0
}

{
	line[NR] = $0
	no[NR] = $1
	count++
}

END{
	for(i=1;i<=count-1;i++)
	{
		for(j=1; j<=count-i-1; j++)
		{
			if(no[j] > no[j+1])
			{
				temp = line[j]
				tempNo = no[j]
				line[j] = line[j+1]
				no[j] = no[j+1]
				line[j+1] = temp
				no[j+1] = tempNo
			}
		}
	}	

	for(i=1;i<=count;i++)
		printf "%s\n",line[i]
}
