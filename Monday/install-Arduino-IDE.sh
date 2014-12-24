#!/bin/bash
echo "Download Arduino IDE"
url=http://arduino.cc/download.php?f=/arduino-1.0.6-linux64.tgz
filename=$(basename "$url")
wget -O $filename "$url"
tar -zxvf $filename
rm $filename

echo "Download Vilros USK code and Install"
url=http://www.vilros.com/ufiles/uskcode.zip
filename=$(basename "$url")
wget -O $filename "$url"
unzip $filename -d $PWD
rm $filename

echo "Move Examples into Arduino IDE"
mv USK\ Guide\ Code/* arduino-1.0.6/examples/
rm -r USK\ Guide\ Code/

echo "Try to Create Desktop link"
cat > ~/Desktop/Arduino.desktop <<_EOF_
[Desktop Entry]
Name=Arduino
Exec=$PWD/arduino-1.0.6/arduino
Icon=$PWD/arduino-1.0.6/reference/img/logo.png
Terminal=false
Type=Application
_EOF_

chmod 755 ~/Desktop/Arduino.desktop

echo "Done!"
