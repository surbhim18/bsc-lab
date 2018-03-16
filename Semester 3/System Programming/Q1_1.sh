argc=$#

if [ $argc -lt 1 ]
then
echo "At least one argument is required"
exit
fi

for((i=argc; i>=1; i--))
do
	eval "j=\${$i}"
	echo -n "$j "
done
echo ""
