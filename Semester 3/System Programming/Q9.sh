
compare()
{
	echo ""	
	cmp $fname1 $fname2
	val=`echo $?`

	if [ $val -eq 0 ]	#the files are same
	then
		echo -e "\nThe files are same."
		rm $fname2
		echo "$fname2 has been deleted."
	else
	echo -e "\nThe files are different. No action required."	
	fi

	echo "-------------------------------------------------"
}


echo "-------------------------------------------------"
echo -e "Enter first filename"
read fname1

echo -e "\nEnter second filename"
read fname2
	
if [ -e $fname1 -a -e $fname2 ]
then
	if [ "$fname1" = "$fname2" ] 
	then
	echo -e "\nBoth files have the same name. Invalid input."
	echo "-------------------------------------------------"
	else
	compare
	fi	
else
echo -e "\nOne or both files do not exist. Please try again. "
echo "-------------------------------------------------"
fi
