BEGIN{
	count=0;
}

{
	temp = $0
	found=0	
	#printf "%s\n",temp;

	for(i=1;i<=count;i++)
	{
		if(temp==arr[i])
		{
			found=1;break;
		}
	}

	if(found==0)
	{
		count++;
		arr[count]=temp
	}	

}

END{
	for(i=1;i<=count;i++)
		printf "%s\n",arr[i];

}
