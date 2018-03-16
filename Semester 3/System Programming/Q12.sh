	argc=$#

	if [ $argc -gt 1 ]
	then
	echo -e "\nOnly one argument should be given.\n";
	exit
	fi
	
	arg=$1
	arg1=`echo $arg | tr -s "."`
	months=`echo $arg1 | tr "." " "`

	month1=`echo $months | cut -d " " -f1`
	month2=`echo $months | cut -d " " -f2`

	#year=`date | cut -d " " -f6`
	set `date`
        year=$6
        #echo $month1
        #echo $month2

	case $month1 in
	Jan*|JAN*) val1=1;;
	Feb*|FEB*) val1=2;;
	Mar*|MAR*) val1=3 ;;
	Apr*|APR*) val1=4;;
	May|MAY) val1=5 ;;
	Jun*|JUN*) val1=6 ;;
	Jul*|JUL*) val1=7 ;;
	Aug*|AUG*) val1=8 ;;
	Sep*|SEP*) val1=9;;
	Oct*|OCT*) val1=10 ;;
	Nov*|NOV*) val1=11 ;;
	Dec*|DEC*) val1=12 ;;
	esac

	case $month2 in
	Jan*|JAN*) val2=1;;
	Feb*|FEB*) val2=2;;
	Mar*|MAR*) val2=3 ;;
	Apr*|APR*) val2=4;;
	May|MAY) val2=5 ;;
	Jun*|JUN*) val2=6 ;;
	Jul*|JUL*) val2=7 ;;
	Aug*|AUG*) val2=8 ;;
	Sep*|SEP*) val2=9;;
	Oct*|OCT*) val2=10 ;;
	Nov*|NOV*) val2=11 ;;
	Dec*|DEC*) val2=12 ;;
	esac

	#echo $val1
	#echo $val2

	if [ $val1 -gt  $val2 ]
	then
		echo -e "\nEntered range is invalid\n"
		exit
	fi

	for((i=val1;i<=val2;i++))
	do
	cal $i $year
	done
