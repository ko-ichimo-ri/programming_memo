#! /bin/bash
echo "" > temp.sh
chmod 777 temp.sh
export LOOP="echo 'hello'; echo \$LOOP >> temp.sh"
echo $LOOP >> temp.sh
./temp.sh &
sleep 3
rm temp.sh

# 削除後に生成されうるので少し待って消す
sleep 1
rm temp.sh