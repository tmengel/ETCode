#!/usr/bin/perl
use Sort::Key qw(keysort nkeysort ikeysort);
system "cat fitoutput/*.dat | sort | uniq > all.dat";
@lines = `cat all.dat`;
@energies = (7.7,11.5,19.6,27,39,62.4,130,200);
@particles = ("pi-","pi+","pi0","ka-","ka+","pba","pro","eta","ome");
$ncent=9;
#This will be the world's ugliest perl script but it will do the job!
for($i=0;$i<=$#lines;$i++){
  chomp($lines[$i]);
  #print "$lines[$i]\n";
  #11.5	pi0	0	52.6322	3.53955	0.921743	61.0166	4.26369	1.93354	126.102	5.06176	8.83005	338	2
  ($energy[$i],$particle[$i],$cb[$i],$dEtdeta,$dEtdetaErr,$dEtdetaErrExtrap,$dEtdy,$dEtdyErr,$dEtdyErrExtrap,$dNdeta,$dNdetaErr,$dNdetaErrExtrap,$npart,$nparterr) = split("\t",$lines[$i]);
  #print "$energy $particle $cb\n";
} 
for($e=0;$e<=$#energies;$e++){
  for($p=0;$p<=$#particles;$p++){
    for($cent=0;$cent<$ncent;$cent++){
      #brute force search for the right line
      for($i=0;$i<=$#lines;$i++){
	if(abs($energies[$e]-$energy[$i])<0.1){
	  if($cb[$i]==$cent){
	    if($particle[$i] eq $particles[$p]){
	      print "$lines[$i]\n";
	    }
	  }
	}
      }
      #print "$e $p $cent\n";
    }
  }
}
