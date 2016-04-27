#!/bin/bash
# Make sure only root can run our script
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use \"sudo\"" 1>&2
  exit 1
fi
echo "Adding to dialout group"
/usr/sbin/usermod -aG dialout $SUDO_USER

echo "Remove Old Arduino IDE"
/usr/bin/apt-get remove -y arduino

echo "Download Arduino code and Install"
url='192.168.22.126/arduino-1.6.5-linux64.tar.xz'
filename=$(basename "$url")
wget -O $filename "$url"
tar xvf $filename
rm $filename

ln -s /usr/share/arduino/examples/ /home/$USER/Downloads/arduino-1.6.5/arduino/examples/

echo "Try to Create Desktop link"
cat > ~/Desktop/Arduino.desktop <<_EOF_
[Desktop Entry]
Name=Arduino
Exec=/home/$USER/Downloads/arduino-1.6.5/arduino
Icon=/usr/share/arduino/lib/arduino_icon.ico
Terminal=false
Type=Application
_EOF_

chmod 755 ~/Desktop/* 
