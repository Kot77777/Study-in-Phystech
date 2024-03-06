d=`date +%m`
for (( COUNTER=0; COUNTER<1000; COUNTER++ )); do
        touch snapshot_$COUNTER.csv
done
