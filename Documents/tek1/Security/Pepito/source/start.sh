#!/bin/sh
#

sudo iptables -A INPUT -p tcp -i wlan0 --destination-port 31337 -j DROP
sudo iptables -A INPUT -p udp -i wlan0 --destination-port 31337 -j DROP
echo "Iptables UP"
env -i LD_LIBRARY_PATH=lib_linux gdb --args ./pepito debug
sudo iptables -D INPUT -p tcp -i wlan0 --destination-port 31337 -j DROP
sudo iptables -D INPUT -p udp -i wlan0 --destination-port 31337 -j DROP
echo "Iptables DOWN"
