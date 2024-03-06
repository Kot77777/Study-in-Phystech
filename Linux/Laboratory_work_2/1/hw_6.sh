d=`date +%m`
for (( COUNTER=0; COUNTER<1000; COUNTER++ )); do
	mv snapshot_$COUNTER.csv snapshot_$d$COUNTER.csv 
done
