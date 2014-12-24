#!/bin/bash
# Make sure only root can run our script
if [[ $EUID -ne 0 ]]; then
  echo "This script must be run as root. Use \"sudo\"" 1>&2
  exit 1
fi
echo "Adding to dialout group"
/usr/sbin/usermod -aG dialout $SUDO_USER

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

