#/bin/sh
rm -rf obj
sudo rm -rf /usr/local/occlum/
make clean
make
sudo make install
