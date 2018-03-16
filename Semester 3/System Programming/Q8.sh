menu()
{
	echo "--------------------------------------------------"
	echo -e "File Options"
	echo -e "1.Display the file."
	echo -e "2.Overwrite the contents of the file."
	echo -e "3.Append data to the file."
	echo "---------------------------------------------------"
	echo -ne "Enter your choice: "
	read ch
	echo "---------------------------------------------------"

	choice
}

choice()
{
	case $ch in
	
	1) echo "Your file is-"
	   echo "-------------------------------------------------" 
	   cat $fname;;	
	
	2) echo "(Press Ctrl+D to save file)"
	   cat > $fname ;;
	
	3) echo "(Press Ctrl+D to save file)"
	   cat >> $fname ;;
	
	*) echo -e "\nPlease enter a valid choice"
	
	esac

	continueYN
}

continueYN()
{
	echo "-------------------------------------------------"
	echo -e -n "Do you wish to continue? : "
	read c
	
	if [ $c = 'y' ]
	then
	menu
	else
	exit
	fi
}

echo "-------------------------------------------------"
echo -e "Enter a filename"
read fname

if test -e $fname
then
	if test -d $fname
	then
	echo "-------------------------------------------------"
	echo "$fname is a directory" 
	echo "-------------------------------------------------"
	else
	menu
	fi 
else
echo "-------------------------------------------------"
echo -e "\nThe file does not exist. Please try again. "
echo "-------------------------------------------------"
fi

