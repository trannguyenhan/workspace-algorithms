<?php
function tinderAction ($account_name) {
$array=[];
for ($i=0;$i<strlen($account_name);$i++)
    {
        if (!in_array($account_name[$i],$array)) $array[count($array)]=$account_name[$i];
    }
    if (count($array)%2 ==0) return "swipe left";
    else  return "swipe right";
}



$account_name = readline();
$result = tinderAction($account_name);
echo $result;