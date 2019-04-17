#!/usr/bin/perl -s

use LWP::Simple;
#$q gets passed from command line and is put into $query string
#CHANGE QUERY LINE TO SUITE YOUR QUERY
print"-q = $q\n";
print"-o = $o\n";
print"-b = $b\n";
print"-db = $db\n"; 

$query ='"' .  $q . '"' .  " [Organism] OR " .  $q . " [All Fields]";

print"query string = $query\n";
if ($db){
	$db = $db;}
else{
	$db = "protein";}
#assemble esearch url
$base = "https://eutils.ncbi.nlm.nih.gov/entrez/eutils/";
#CHANGE db= IF NEEDED
$url = $base . "esearch.fcgi?db=" . $db . "&term=$query&usehistory=y";

#make http call with get()
$output = get($url);

#parse WedEnv , QueryKey, and Count 
$web = $1 if ($output =~ /<WebEnv>(\S+)<\/WebEnv>/);
$key = $1 if ($output =~ /<QueryKey>(\d+)<\/QueryKey>/);
$count = $1 if($output =~ /<Count>(\d+)<\/Count>/);

#open output file for writing
#CHANGE NAME OF OUT TO YOUR OUTPUT FILE
#$o gets passed from command line and is the output file name
open(OUT, ">$o");

#retrieve data in batches
# retmax is the batch size. change if needed

if($b){
	$retmax = $b;}
else{
	$retmax = 500;}
print"Fetching datasets for $q ...\n";
for ($retstart = 0; $retstart < $count; $retstart += $retmax){

	$efetch_url = $base . "efetch.fcgi?db=" . $db . "&WebEnv=$web";
	$efetch_url .= "&query_key=$key&retstart=$retstart";
	$efetch_url .= "&retmax=$retmax&rettype=fasta&retmode=text";
	$efetch_out = get($efetch_url);
	print OUT "$efetch_out";
}
print"Created output file $o in working directory\n";
close OUT;
