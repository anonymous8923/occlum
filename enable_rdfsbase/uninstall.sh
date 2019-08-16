sudo /sbin/modprobe -r enable_rdfsbase
sudo rm -rf "/lib/modules/"`uname -r`"/kernel/drivers/occlum"
sudo /sbin/depmod
sudo /bin/sed -i '/^enable_rdfsbase$/d' /etc/modules
