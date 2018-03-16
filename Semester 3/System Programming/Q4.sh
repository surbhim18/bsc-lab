menu()
{
	echo "--------------------------------------------------"
	echo -e "File Options"
	echo -e "1.Display the file."
	echo -e "2.Display the permissions of the file."
	echo -e "3.Find a pattern in the file."
	echo -e "4.Replace all letters 'e' by 'a'"
	echo "---------------------------------------------------"
	echo -e "Enter your choice: "
	echo "---------------------------------------------------"
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

	2) echo -e "\nThe permissions of the file are-"
           ls -l $fname | cut -d " " -f1,9;;
	
	3) echo -e "\nEnter the pattern to be searched-"
	   read patt

	   echo "-------------------------------------------------"         
   	   echo -e "	1.Ignoring case"
	   echo -e "	2.Case sensitive"
	   echo "---------------------------------------------------"
	   echo -ne "	Enter your choice: "
	   read ch1
	   echo "---------------------------------------------------"
	   
   	   case $ch1 in
	   
	   1)  grep -i $patt $fname
	       
		if [ $? -ne 0 ]
		then
			echo "Pattern not found."
		fi ;;
	
	   2) grep $patt $fname
		
		if [ $? -ne 0 ]
		then
			echo "Pattern not found."
		fi ;;
	
	   *) echo -e "\nPlease enter a valid choice (1 or 2)"
	   esac ;;

	
	4) cat $fname | tr 'e' 'a' ;;
	
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

