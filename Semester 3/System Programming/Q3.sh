printMonthYear()
{

	if [ $argc -eq 1 ]
	then
	year=`date | cut -d " " -f6`
	else
	year=$arg2
	fi
	
	case $arg1 in
	Jan*|JAN*) cal 01 $year ;;
	Feb*|FEB*) cal 02 $year ;;
	Mar*|MAR*) cal 03 $year ;;
	Apr*|APR*) cal 04 $year ;;
	May|MAY) cal 05 $year ;;
	Jun*|JUN*) cal 06 $year ;;
	Jul*|JUL*) cal 07 $year ;;
	Aug*|AUG*) cal 08 $year ;;
	Sep*|SEP*) cal 09 $year ;;
	Oct*|OCT*) cal 10 $year ;;
	Nov*|NOV*) cal 11 $year ;;
	Dec*|DEC*) cal 12 $year ;;
	*) cal $arg1
	esac
}

	argc=$#
	arg1=$1
	arg2=$2

	if [ $argc -gt 2 ]
	then
	echo -e "\nMaximum no of arguments are 2\n";
	exit
	fi

	if [ $argc -eq 0 ]
	then
	cal
	elif [ $argc -ge 1 ]
	then
	printMonthYear	
	fi
