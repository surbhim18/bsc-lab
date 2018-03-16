
	argc=$#

	if [ $argc -eq 0 ]
	then
	echo -e "\nAt least one argument is required\n"
	exit
	fi

	year=`date | cut -d " " -f6`
	
	for arg in $*
	{		
		arg=`echo $arg | tr [:lower:] [:upper:]`
		
		case $arg in
		JAN*) val=1;;
		FEB*) val=2;;
		MAR*) val=3 ;;
		APR*) val=4;;
		MAY*) val=5 ;;
		JUN*) val=6 ;;
		JUL*) val=7 ;;
		AUG*) val=8 ;;
		SEP*) val=9;;
		OCT*) val=10 ;;
		NOV*) val=11 ;;
		DEC*) val=12 ;;
		esac

		cal $val $year
	}
