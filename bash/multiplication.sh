echo "enter the number"
read num

for ((i=0 ;i<=10; i++))
do
    echo $(($num * $i))
done