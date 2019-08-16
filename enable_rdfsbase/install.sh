sudo mkdir -p "/lib/modules/"`uname -r`"/kernel/drivers/occlum"
sudo cp enable_rdfsbase.ko "/lib/modules/"`uname -r`"/kernel/drivers/occlum"
sudo sh -c "cat /etc/modules | grep -Fxq isgx || echo enable_rdfsbase >> /etc/modules"
sudo /sbin/depmod
sudo /sbin/modprobe enable_rdfsbase
