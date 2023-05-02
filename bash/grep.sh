echo "Enter the filename"
read file
echo "Enter the pattern"
read pattern

grep -i "$pattern" $file
