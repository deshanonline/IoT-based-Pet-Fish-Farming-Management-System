<?php
  
    $url = 
    'python/data.csv';
    $file_name = basename($url);
     
    if (file_put_contents($file_name, file_get_contents($url)))
    {
        echo "File downloaded successfully.";
		header("refresh:1;url=data.csv");
    }

    else
    {
        echo "File downloading failed.  Automatically redirect to gallery page";
		header("refresh:2;url=gallery.php");
    }
?>

	Click here to go Home. <a href="gallery.php">Click here</a>