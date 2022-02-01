<code>

<?php 
$light = $_GET['light'];
if($light == "on")
    { $file = fopen("light.json", "w") or die("can't open file");
    fwrite($file, '{"light": "on"}'); fclose($file);
    } 
    else if ($light == "off") 
    { $file = fopen("light.json", "w") or die("can't open file"); fwrite($file, '{"light": "off"}');
    fclose($file); 
    } 
?> 
<html>
<head>
<meta charset="utf-8"> 
<meta http-equiv="X-UA-Compatible" content="IE=edge"> 
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="Author" content="gerard IoT">
<style type="text/css">
input
{
font-size:22px;
text-align: center;
width: 150px;
height: 50px; 
}
#on
{
background-color:LIGHTGREEN;
}
#off
{
background-color:RED;
}
#texte
{
font-size:22px;
margin-top: 5px; text-align:center

}
</style>
<title>Controle d'une LED via WEB avec ESP8266</title>
</head> 
<body>
<div id ="texte">
<a href="?light=on"><input id="on" type="button" value="ON"></a> <br />
<a href="?light=off"><input id="off" type="button" value="OFF"></a> <br />

<?php
if($light=="on") { echo("La LED est Allumée"); }
else if ($light=="off") { echo("La LED est Eteinte"); } 
else { echo ("En attente d'une action ON/OFF"); } 
?> 
</div> </div> </div> 
</body> 
</html>

</code>