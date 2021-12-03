for num in {1..25}
do
if [ $num -lt 10 ]
then
    mkdir 0$num
    cd 0$num
        > 1.cpp
        > 2.cpp
else
    mkdir $num
    cd $num
        > 1.cpp
        > 2.cpp
fi
cd ..
done
