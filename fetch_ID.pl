#!/usr/bin/perl -s 

use LWP::Simple;
print"-dbfrom = $dbfrom\n";
print"-dbto = $dbto\n";
print"-id= $id\n";

my @ids = split /,/,$id;

print @ids;






$base = "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/elink.fcgi?" 
$linkUrl = $base . "dbfrom=" . $dbfrom . "&db=" . &dbto . "&id=" . $id;
open(OUT,">idlink.xml");
$link_result = get($base);
print OUT "$link_result";
close OUT;
