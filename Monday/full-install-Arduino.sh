#!/bin/bash
# Make sure only root can run our script
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use \"sudo\"" 1>&2
  exit 1
fi
echo "Adding to dialout group"
/usr/sbin/usermod -aG dialout $SUDO_USER

echo "Installing Arduino IDE"
/usr/bin/apt-get install arduino

echo "Download Vilros USK code and Install"
url=http://www.vilros.com/ufiles/uskcode.zip
filename=$(basename "$url")
wget -O $filename "$url"
unzip $filename -d $PWD
rm $filename

echo "Move Examples into Arduino IDE"
mv USK\ Guide\ Code/* /usr/share/arduino/examples/
rm -r USK\ Guide\ Code/

echo "Try to Create Desktop link"
cat > ~/Desktop/Arduino.desktop <<_EOF_
[Desktop Entry]
Name=Arduino
Exec=/usr/bin/arduino
Icon=/usr/share/arduino/lib/arduino_icon.ico
Terminal=false
Type=Application
_EOF_

chmod 755 ~/Desktop/* 

#echo "Installing JRE - needed for Arduino IDE"
#/usr/bin/apt-get install default-jre

read -p "Computer needs to restart. Now? " -n 1 -r
if [[ ! $REPLY =~ ^[Yy]$ ]]
then
  echo
  echo "Computer needs to restart before Arduino will work"
  exit 1
else
  echo
  echo "Rebooting..."
  sleep 3
  /sbin/reboot
fi

