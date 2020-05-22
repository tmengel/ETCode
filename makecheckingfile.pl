#!/usr/bin/perl
$i=1;
$start=0;
$stop=10;
$outname = "fitoutput/textSTART$start"."STOP$stop.txt";
print "grep NDF $outname | sed 's/\_/:/g'  > /tmp/text.txt\n";
$n = 10;
for($i=10;$i<=640;$i+=10){
  $start=$i;
  $stop = $i+$n;
  $outname = "fitoutput/textSTART$start"."STOP$stop.txt";
  print "grep NDF $outname | sed 's/\_/:/g'  >> /tmp/text.txt\n";
}
