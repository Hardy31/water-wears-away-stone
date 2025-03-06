#!/bin/bash

echo "Путь к файлу: $1"
echo "Строка для замены: $2"
echo "Замена: $3"

file_path=$1

if [ -f "$file_path" ]; then # 

    if [ -z $2 ]; then 
        echo "Не задан параметр [Строка поиска]"
        exit
    fi
    if [ -z $3 ]; then 
        echo "Не задан параметр [Строка замены]"
        exit
    fi

    sed -i '' "s/$2/$3/g" $1

    path="src/$file_path"
    size=$(stat -F "$file_path" | awk '{print $5}') #Размер файла
    currentdate=$(date -r $file_path "+%Y-%m-%d %H:%M") #Дата последнего изменения
    hash=$(shasum -a 256 $file_path | awk '{print $1}') #Хэш

    echo "$path - $size - $currentdate - $hash - sha256" >> files.log #Запись в файл лога
else 
    echo "$file_path не найден!"
fi

