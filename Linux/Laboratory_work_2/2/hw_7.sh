filename="1.txt"

m1=$(md5sum "$filename")

while true; do

  # md5sum is computationally expensive, so check only once every 10 seconds
  sleep 10

  m2=$(md5sum "$filename")

  if [ "$m1" != "$m2" ] ; then
    echo "ERROR: File has changed!" >&2 
    exit 1
  fi
done
