<?php
function selectTeam ($H, $heights) {
	$x=0;
	for ($i=0;$i<count($heights);$i++)
		{
			if ($heights[$i]==$H){
				$x++;
				$tong[$x]=$H;
				
				if ($H<$heights[$i+1]){
					$y=$i+1;
					while ($heights[$y]>$H){
						$tong[$x]+=$heights[$y];
						$y +=1;
						
					}
				}
				if ($H<$heights[$i-1]){
					$y=$i - 1;
					while ($heights[$y]>$H){
						$tong[$x]+=$heights[$y];
						$y -=1;
						
					}
				}
				
			}
		}
		$max=0;
		for ($i=1;$i<count($tong);$i++)
			if ($tong[$i]>$max) $max=$tong[$i];
	return  $max ;
}



$H = (int)readline();
$heights_count = intval(trim(fgets(STDIN)));
$heights = [];
for ($i = 0; $i < $heights_count; $i++) {
	$heights_item = intval(trim(fgets(STDIN)));
	$heights[] = $heights_item;
}
$result = selectTeam($H, $heights);
echo $result;

