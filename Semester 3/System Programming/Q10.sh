
mergeAndSort()
{
	echo "-------------------------------------------------"	
	sort -m $fname1 $fname2 $fname3 > merge
	echo "Merged and sorted file :-"
	echo "-------------------------------------------------"
	sort merge | more
	rm merge
}




echo "-------------------------------------------------"
echo -e "Enter first filename"
read fname1

if test -e $fname1
then
	echo -e "\nEnter second filename"
	read fname2
	
	if test -e $fname2
	then
		echo -e "\nEnter third filename"
		read fname3
	
		if test -e $fname3
		then
		mergeAndSort
		else
		echo -e "\nThis file does not exist. Please try again. "
		fi	
	else
	echo -e "\nThis file does not exist. Please try again. "
	fi	
else
echo -e "\nThis file does not exist. Please try again. "
fi
echo "-------------------------------------------------"
