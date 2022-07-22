<?php session_start(); 
if(!isset($_SESSION['UserData']['Username'])){
header("location:login.php");
exit;
}
?>

<!DOCTYPE html>
<html>
<head>
  <title>Fish Image Capturing System</title>
  <link rel="icon" type="image/x-icon" href="favicon.ico">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    .flex-container {
      display: flex;
      flex-wrap: wrap;
    }
    .flex-container > div {
      text-align: center;
      margin: 10px;
    }
    
    * {box-sizing: border-box;}

body { 
  margin: 0;
  font-family: Arial, Helvetica, sans-serif;
}

.header {
  overflow: hidden;
  background-color: #19302E;
  padding: 20px 10px;
}

.header a {
  float: left;
  color: white;
  text-align: center;
  padding: 12px;
  text-decoration: none;
  font-size: 18px; 
  line-height: 25px;
  border-radius: 4px;
}

.header a.logo {
  font-size: 25px;
  font-weight: bold;
}

.header a:hover {
  background-color: #ddd;
  color: black;
}

.header a.active {
  background-color: dodgerblue;
  color: white;
}

.header-right {
  float: right;
}

footer{
  background-color: #19302E;
  border-top: 1px solid #6EB981;
  font-size: 17px;
  padding: 15px 5px;
  color: #ffffff;
  text-align: center;
}


@media screen and (max-width: 500px) {
  .header a {
    float: none;
    display: block;
    text-align: left;
  }
  
  .header-right {
    float: none;
  }
}
@media {
  .footer-links li {
    display: inline;
  }
}
  </style>
</head><body>
<div class="header">
  <a href="#" class="logo">Fish Image Capturing System</a>
  <div class="header-right">
    <a class="active" href="logout.php">Logout</a>
  </div>
  </div>

<div style="text-align:center;">
  <p><b>System captures images of fish every 4 hours</b></p>
  <p><b>Click on the photo to see the full screen</b></p>
  <div class="header-center">
    <a class="active" href="python/script.php"><b>Calculate Population</b></a>
	<br>
	<br>
	<a class="active" href="download.php"><b>Download Data File</b></a>
  </div>
</div>
<?php
  // Image extensions
  $image_extensions = array("png","jpg","jpeg","gif");

  // Check delete HTTP GET request - remove images
  if(isset($_GET["delete"])){
    $imageFileType = strtolower(pathinfo($_GET["delete"],PATHINFO_EXTENSION));
    if (file_exists($_GET["delete"]) && ($imageFileType == "jpg" ||  $imageFileType == "png" ||  $imageFileType == "jpeg") ) {
      echo "File found and deleted: " .  $_GET["delete"];
      unlink($_GET["delete"]);
    }
    else {
      echo 'File not found - <a href="gallery.php">refresh</a>';
    }
  }
  // Target directory
  $dir = 'uploads/';
  if (is_dir($dir)){
    echo '<div class="flex-container">';
    $count = 1;
    $files = scandir($dir);
    rsort($files);
    foreach ($files as $file) {
      if ($file != '.' && $file != '..') {?>
        <div>
          <p><a href="gallery.php?delete=<?php echo $dir . $file; ?>">Delete file</a> - <?php echo $file; ?></p>
          <a href="<?php echo $dir . $file; ?>">
            <img src="<?php echo $dir . $file; ?>" style="width: 350px;" alt="" title=""/>
          </a>
       </div>
<?php
       $count++;
      }
    }
  }
  if($count==1) { echo "<p>No images found</p>"; } 
?>
  </div>
  
</body>
<section id="footer">
        <footer>Fish Image Capturing System by Vihanga Deshan &copy; 2022 All Rights Reserved</footer>
    </section>

</html>