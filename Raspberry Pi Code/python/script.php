<?php 

$command = escapeshellcmd('python3 code.py');
$output = shell_exec($command);
echo $output;

header("refresh:5;url=../gallery.php");
?>
<br>
Please wait 5 seconds to be automatically redirected Galley Page. If its not redirected <a href="../gallery.php">Click here</a>
