
hour=`date | cut -d " " -f4 | cut -d ":" -f1`

if [ $hour -ge 0 -a $hour -le 11 ]
then
echo -e "\nGood Morning\n" 
elif [ $hour -ge 12 -a $hour -le 15 ]
then
echo -e "\nGood Afternoon\n" 
elif [ $hour -ge 16 -a $hour -le 19 ]
then
echo -e "\nGood Evening\n" 
else
echo -e "\nGood Night\n" 
fi
