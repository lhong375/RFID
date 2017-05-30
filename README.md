# How To
1. connect uno with your desktop using usb
2. open Arduino
3. select board (Tools > Board > Arduino/blabla uno)
4. select port (Tools > Port > /dev/cu.usbmodemfd121...)

5. Load Library First
Sketch > Include Library > Add .ZIP Library > load rfid-master.zip
6. Load ReadNUID/ReadNUID.ino

9. Open Serial Monitor, that where we can see output (Tools > Serial Monitor)

8. in Arduino, click 'verify', after it's done without error, click 'upload', it will upload the code to board

9. in the Serial Monitor, you will see a message "Garage is OPEN", yay, we are in business !!! 
<p> Tap the fob to sensor, it will pick up its NUID, just like when a car drive into garage
the 7Segment will display '1'</p>
<p> Tap the fob again, it will pick up and recognize its NUID, just like a car leaving garage
the 7Segment will display '-1'</p>

<h2>Note</h2>
<p>since we only have one fob, there is only one car, code logic for other cars hasn't been completly implemented yet.</p>

#OLD REAMDE 
# RFID
Download the librarby. Then follow the illustrations given in the tutorial for Security System using RFID (hackster.io/Aritro)
