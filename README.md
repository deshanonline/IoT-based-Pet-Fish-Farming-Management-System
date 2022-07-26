<h1 align="center"> IoT based Pet Fish Farming Management System 🐠</h1>

In this system I used microcontroller-based fish farming pond maintained using the sensors.
The PH sensor used for measuring the water quality of fish tank. Also, water level sensor used for 
identifying the water level of fish tank. Furthermore, I used automated food feeding system for 
this, then farmer no need to warry about feeding the fish. There is automated food feeding system 
already in the market, but that small device may be not appropriate the outdoor fish farming tanks.
When it comes to fish farming, a lot of fish are in one tank, but only a limited number of fish can 
be caught in one tank. The temperature sensor monitors the temperature in the tank and controls 
the temperature in the tank with a heater. We also used a turbulence sensor to measure Turbulence 
rate or opacity, Arduino gravitational perturbation the sensor senses the quality of the water. The 
system also adds an image processing-based population management feature as the farmer loses 
time for his other work while visiting each tank. The images were taken by attaching a camera to 
the selected locations. Another problem for farmers is the removal of water from these tanks and 
refilling. It is now done by manually. This includes a feature that automatically removes stale water 
and fills it with fresh water if the pH of the water changes adversely. It is also expected to be 
refilled not only when the pH changes, we can schedule this process as what farmer wants. E.g.
farmer wants to change water every two days. The microcontroller is used to control the entire 
circuit of the system. 

<h2>Aims of the Project </h2>
  <p>The aim of this project is to provide a solution for fish farmers where they are able to monitor 
key factors affecting in fish farming which are temperature, pH level and the water level in the 
tanks, from any location in the world. 
        <li>Generally, fish farmers do their day-to-day activities in the farm manually.</li>
        <li>Due to the above reason the unnecessary amount of time is consumed for simple tasks and 
sometimes due to errors in observations financial losses can be occurred.</li>
        <li>When using this system, they can do conduct their activities with minimum risk and also 
save time as well.</li>
  </p>

<h2>Hardware Requirement</h2>
  <li>Liquid Water PH Value Detection Sensor with Control Board</li>
  <li>ESP32 OV2640 Camera Bluetooth Wi-Fi Board</li>
  <li>Digital Waterproof Temperature Probe DS18B20 100CM</li>
  <li>NodeMCU WIFI Internet Development Board ESP8266 CP2102</li>
  <li>Mini Micro Submersible Water Pumps DC 2.5-6V Amphibious Type</li>
  <li>Servo Motor SG90 9G Micro Servo Motor</li>
  <li>Water Level Float Switch</li>
  <li>Raspberry Pi</li>


<h2>Software requirement </h2>
  <li>Arduino Language</li>
  <li>Blynk Server</li>
  <li>Fritzing</li>
  <li>Open CV</li>
  <li>Open CV</li>
  <li>SQLite</li>


<h2> Physical Design</h2>
<p>There are two main types of this system.</p>

<h2> Part #01 - Diagram</h2>
<p>Below is the section that uses all the environmental data 
and other features of the fish tank</p>
<p align="left"> <a href="#" target="_blank" rel="noreferrer"> <img src="https://github.com/vihangad/IoT-based-Pet-Fish-Farming-Management-System/blob/master/Diagrams/01.jpg?raw=true" alt="Diagram" width="auto" height="auto"/> </a> </p>

<h2> Part #02 - Diagram</h2>
<p>The second part of this system is to calculate the fish population based on the images. Due 
to the diversity and complexity of the underwater environment, underwater images are usually 
subjected to intense noise, which reduces the quality of the underwater images and affects the 
accuracy of image analysis. Below is how the fish population is calculated based on the images.
</p>
<p align="left"> <a href="#" target="_blank" rel="noreferrer"> <img src="https://github.com/vihangad/IoT-based-Pet-Fish-Farming-Management-System/blob/master/Diagrams/02.jpg?raw=true" alt="Diagram" width="auto" height="auto"/> </a> </p>

<h2>Web UI Design</h2>
<p>This is login page of the system</p>
<p align="left"> <a href="#" target="_blank" rel="noreferrer"> <img src="https://github.com/vihangad/IoT-based-Pet-Fish-Farming-Management-System/blob/master/Diagrams/05.jpg?raw=true" alt="Diagram" width="auto" height="auto"/> </a> </p>
<br>

<p>All the photos taken of the fish can be seen through this dashboard</p>
<p align="left"> <a href="#" target="_blank" rel="noreferrer"> <img src="https://github.com/vihangad/IoT-based-Pet-Fish-Farming-Management-System/blob/master/Diagrams/06.jpg?raw=true" alt="Diagram" width="auto" height="auto"/> </a> </p>

<h3 align="left">Use Languages and Tools:</h3>
<p align="left"> <a href="https://www.arduino.cc/" target="_blank" rel="noreferrer"> <img src="https://cdn.worldvectorlogo.com/logos/arduino-1.svg" alt="arduino" width="40" height="40"/> </a> <a href="https://getbootstrap.com" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/bootstrap/bootstrap-plain-wordmark.svg" alt="bootstrap" width="40" height="40"/> </a> <a href="https://www.w3schools.com/css/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/css3/css3-original-wordmark.svg" alt="css3" width="40" height="40"/> </a> <a href="https://www.w3.org/html/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/html5/html5-original-wordmark.svg" alt="html5" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> <a href="https://opencv.org/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/opencv/opencv-icon.svg" alt="opencv" width="40" height="40"/> </a> <a href="https://www.php.net" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/php/php-original.svg" alt="php" width="40" height="40"/> </a> <a href="https://www.python.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> </a> <a href="https://www.sqlite.org/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/sqlite/sqlite-icon.svg" alt="sqlite" width="40" height="40"/> </a> </p>

<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://twitter.com/deshanonline" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="deshanonline" height="30" width="40" /></a>
<a href="https://linkedin.com/in/deshanonline" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="deshanonline" height="30" width="40" /></a>
<a href="https://fb.com/deshanonline" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="deshanonline" height="30" width="40" /></a>
<a href="https://instagram.com/deshanonline" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/instagram.svg" alt="deshanonline" height="30" width="40" /></a>
<a href="https://www.youtube.com/c/vihangadeshanofficial" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/youtube.svg" alt="vihangadeshanofficial" height="30" width="40" /></a>
</p>

  
