
echo -e "\nEnter filename: "
read fname

if test -f $fname
then
echo "Removing spaces";
else
echo "The file doesn't exist. Exiting...";
exit
fi

cat $fname | tr '\t' ' ' > temp1
cat temp1 | tr -s ' \n' > temp2

rm temp1
rm $fname
mv temp2 $fname 

echo -e "\nFile after removing spaces :- "
cat $fname 
