<center>Octave MQTT Toolkit</center>
----------------------

---

Introduction
============

This is a basic implementation of the Matlab toolkit extension.

Requirements
============

The toolkit requires the [paho-c](https://www.eclipse.org/paho/) library. 
the board.

Installing
==========

To install, run the octave package manager:

1. To install from source forge:

    `pkg install https://sourceforge.net/projects/octave-mqtt/files/vXXXXXXX/octave-mqtt-XXXXXXX.tar.gz/download`

2. To install from a local tarball.

    `pkg install octave-mqtt-XXXXXXX.tar.gz`

    Where XXXXXXX is the version of the the downloaded tarball.

Usage:
======

1. Load the octave-mqtt package.
   
    `pkg load mqtt`

2. Connect to a server using the mqttclient function

3. Use the subscribe, read and write commands to read and write data


Known limitations and bugs
==========================

