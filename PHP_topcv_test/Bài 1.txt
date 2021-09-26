Bài 1:
<?php
function recoverText ($orientation, $text) {
$row[0]="q w e r t y u i o p";
$row[1] = explode(' ',$row[0]);
$row[0]="a s d f g h j k l ;";
$row[2] = explode(' ',$row[0]);
$row[0]="z x c v b n m , . /";
$row[3] = explode(' ',$row[0]);
$x=1;
if ($orientation == 'P') $x=-1;
for ($i=0;$i<strlen($text);$i++){
    for ($j=1;$j<=3;$j++)
        {$k=array_search($text[$i],$row[$j]);
            if ( $k>-1) $text[$i]=$row[$j][$k+$x];
        }
}
return $text;
}




$orientation = readline();
$text = readline();
$result = recoverText($orientation, $text);
echo $result;
