
	argc=$#

	if [ $argc -eq 0 ]
	then
	echo -e "\nAt least one argument is required\n"
	exit
	fi

	year=`date | cut -d " " -f6`
	
	for((i=1;i<=argc;i++))
	{
		eval "arg=\${$i}"	
				
		case $arg in
		Jan*|JAN*) val=1;;
		Feb*|FEB*) val=2;;
		Mar*|MAR*) val=3 ;;
		Apr*|APR*) val=4;;
		May*|MAY*) val=5 ;;
		Jun*|JUN*) val=6 ;;
		Jul*|JUL*) val=7 ;;
		Aug*|AUG*) val=8 ;;
		Sep*|SEP*) val=9;;
		Oct*|OCT*) val=10 ;;
		Nov*|NOV*) val=11 ;;
		Dec*|DEC*) val=12 ;;
		esac

		cal $val $year

	}
