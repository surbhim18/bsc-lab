
fold()
{
	awk '{
		len=length;
		for(i=$0; length(i)>30;)
		{
			print substr(i,1,30);
			
			len = len-30;
			i = substr(i,31,len);
		}
	   	print i;
	     }' $fname 
}


echo -e "\nEnter filename: "
read fname

if test -f $fname
then
	fold
else
	echo "The file does not exist"
	exit
fi
