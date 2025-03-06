#!/bin/bash

# Анализатор логов
# Организовать вывод в консоль 
#   1. Общее количество записей
#   2. Количество уникальных файлов
#   3. Количество изменений, приведших к изменению хэша

input_file=$1
#echo $input_file

arrcount=0
while IFS= read -r line
do
  lines_amount=$[ $lines_amount + 1 ] # Считаем количество строк в файле

    file_name=$(echo "$line" | awk '{print $1}') # Массив имен файлов
    hash=$(echo "$line" | awk '{print $8}') # Массив хешей
    #echo "$file_name $hash"
    
    arrcount=$((arrcount+1))
    fnarray[$arrcount]=$file_name #Заполняем массив именами файлов
    hsharray[$arrcount]=$hash #Заполняем массив хэшами

done <  $input_file
echo "Количество строк в файле логов [$input_file]: $lines_amount"

echo "Количество уникальных файлов: "
(IFS=$'\n'; sort <<< "${fnarray[*]}") | uniq -c | wc -l

echo "Количество уникальных хешей: "
(IFS=$'\n'; sort <<< "${hsharray[*]}") | uniq -c | wc -l



