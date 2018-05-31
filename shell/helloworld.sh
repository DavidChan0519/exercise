#!/bin/bash

var="hello world"
echo $var

your_name="chengwei"

sentence_1="type 1 :hello "${your_name}" nice to meet u"
sentence_2="type 2 :hello ${your_name} nice to meet u"

echo $sentence_1
echo $sentence_2

echo ${#your_name}
echo ${#sentence_1}

read my_name
echo -e "your name is "${my_name}"\n"

echo "I love u"
