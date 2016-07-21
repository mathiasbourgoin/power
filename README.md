Power consumption measurement platform
--------------------------------------

This project proposes a hardware and software platform to measure power consumption of a Jetson TK1 board.

It is composed of 3 parts:
- the measurement board (Arduino) which sends data (current intensity) to the host (serial),
- the platform benchmarks and utilities, which allow to control the CPUs/GPU and send events to the host (serial),
- the host which receives both current intensity and events and merge them.


Requirements
------------

- Boost 1.60 with boost_system library
