#INCORRECT PROGRAM

echo $* |
awk '{
	if(length($0)!=8)
	{
		print "INVALID DATE"
		exit
	}
	
	mm = substr($0,1,2)
	dd = substr($0,4,2)
	yy = substr($0,7,2)

	if(mm < 1|| mm >12)
	{
		print "INVALID MONTH"
		exit
	}	

	if(dd < 1)
	{
		print "INVALID DAY"
		exit
	}

	if(((mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)&& dd>31) || ((mm==4 || mm==6 || mm==9 || mm==11)&& dd>30) || (mm==2 && dd >28))
	{
		print "INVALID DAY"
		exit
	}
	printf "Day: %s  Month: %s  Year: %s\n",dd,mm,yy

      }'
