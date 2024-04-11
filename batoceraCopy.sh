#!/bin/bash
# Script to perform installation and file copying tasks

# Run make install
sudo make install

# Create directory structure under compiled folder
mkdir -p compiled
mkdir -p compiled/userdata
mkdir -p compiled/usr/bin
mkdir -p compiled/usr/include
mkdir -p compiled/usr/lib
mkdir -p compiled/usr/share

# Copy files to compiled/usr/bin
sudo cp /usr/bin/emitter /usr/bin/inputseeker /usr/bin/ledspicerd /usr/bin/processLookup /usr/bin/rotator compiled/usr/bin/

# Copy files to compiled/usr/include
sudo cp -r /usr/include/ledspicer compiled/usr/include/

# Copy files to compiled/usr/lib
sudo cp -r /usr/lib/ledspicer compiled/usr/lib/
sudo cp -r /usr/lib/pkgconfig compiled/usr/lib/

# Copy files to compiled/usr/share
sudo cp -r /usr/share/ledspicer compiled/usr/share/

#tar gz files

tar -czvf extension_ledspicer.tar.gz /compiled/
