#!/bin/bash
username=`whoami`
if [ $username != "root" ]; then
	echo "You must run this using sudo."
	exit 1
fi
echo $SUDO_USER
usermod -a -G dialout $SUDO_USER
apt-get install libftdi-dev gawk
chgrp dialout hardware/tools/papilio/papilio_loader/papilio-prog
chgrp dialout hardware/tools/papilio/papilio-prog
chgrp dialout hardware/tools/papilio/lin32/papilio-prog
chgrp dialout tools/Papilio_Loader/programmer/linux32/papilio-prog
echo 'SUBSYSTEMS=="usb", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="6010", GROUP="dialout"' > /etc/udev/rules.d/papilio.rules
echo 'SUBSYSTEMS=="usb", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="7bc0", GROUP="dialout"' >> /etc/udev/rules.d/papilio.rules
echo 'ACTION=="add", ATTRS{idVendor}=="0403", ATTRS{idProduct}=="7bc0", RUN+="/sbin/modprobe ftdi_sio" RUN+="/bin/sh -c '"'"'echo 0403 7bc0 > /sys/bus/usb-serial/drivers/ftdi_sio/new_id'"'"'"' >> /etc/udev/rules.d/papilio.rules
udevadm control --reload
echo "You may need to log out and back in for the changes to take affect, if that does not work then reboot."
su $SUDO_USER
