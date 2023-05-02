echo filename
read file_path

number_of_lines=`wc --lines < $file_path`
number_of_words=`wc --word < $file_path`
chars=`wc --char < $file_path`

echo "Number of lines: $number_of_lines"
echo "Number of words: $number_of_words"
echo "Number of characters: $chars"