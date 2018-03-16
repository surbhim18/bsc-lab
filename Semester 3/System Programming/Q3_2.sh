	argc=$#

	if [ $argc -gt 2 ]
	then
	echo -e "\nMaximum no of arguments are 2\n";
	exit
	fi

	if [ $argc -eq 0 ]
	then
	month=`date|cut -d " " -f2`
	year=`date | cut -d " " -f6`
	elif [ $argc -eq 1 ]
	then
		case $1 in
		[1-9]*) year=$1
			month=0 ;;
		*)	month=$1
			year=`date | cut -d " " -f6` ;;
		esac
	else
	month=$1
	year=$2
	fi
	
	month=`echo $month | tr [:lower:] [:upper:]`
		
	case $month in
	JAN*) month=1;;
	FEB*) month=2;;
	MAR*) month=3 ;;
	APR*) month=4;;
	MAY*) month=5 ;;
	JUN*) month=6 ;;
	JUL*) month=7 ;;
	AUG*) month=8 ;;
	SEP*) month=9;;
	OCT*) month=10 ;;
	NOV*) month=11 ;;
	DEC*) month=12 ;;	
	esac

	
	if [ $month -eq 0 ]
	then 
	cal $year
	else
	cal $month $year
	fi
