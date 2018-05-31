# !/bin/sh  
  
type=1    # 1, 2, 3(a,abc,123)  
  
  
function getVal()
{
	echo "$1"
}

 
if [ "$type" == "1" ]; then
    for((i=0;i<4;i++))
    do
        eval getVal $i
    done
elif [ "$type" == "2" ]; then
    echo "type"
else
    echo "none"
fi
