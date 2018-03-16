menu()
{
	echo "--------------------------------------------------"
	echo -e "File Options"
	echo -e "1.Display the file."
	echo -e "2.Display last n lines of the file."
	echo -e "3.Sort the file."
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
	
	2) echo -ne "\nEnter n: "
	   read n
	   echo "-------------------------------------------------"
	   tail -$n $fname  ;;

	3) echo -e "	1.Ascending order."
	   echo -e "	2.Descending order."
	   echo "---------------------------------------------------"
	   echo -ne "	Enter your choice: "
	   read ch1
	   echo "---------------------------------------------------"
	   
   	   case $ch1 in
	   
	   1) sort $fname   ;;
	
	   2) sort -r $fname ;;
	
	   *) echo -e "\nPlease enter a valid choice ( 1 or 2)"
	   esac ;;


	*) echo -e "\nPlease enter a valid choice"
	   esac

	continueYN
}

continueYN()
{
	echo "-------------------------------------------------"
	echo -e -n "\nDo you wish to continue? : "
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
menu
else
echo -e "\nThe file does not exist. Please try again. "
fi

