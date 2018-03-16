
hour=`date | cut -d " " -f4 | cut -d ":" -f1`

case $hour in
[0-1][0-1]|0[2-9] ) echo -e "\nGood Morning" ;;
 
1[2-5]) echo -e "\nGood Afternoon" ;;

1[6-9]) echo -e "\nGood Evening" ;;

*) echo -e "\nGood Night";; 

esac

echo ""
