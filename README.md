escoops
=======

Run a command when ESC key is hit

Usage
-----

```
$ escoops 'echo Oops I touched ESC key!'
```

To tweet when ESC is hit, it is possible to use a command line client like [Tw](http://shokai.github.io/tw/):

```
$ escoops 'tw --yes Oops I touched ESC key at `date +%H:%M`!'
```

Installation
------------
Programmed and tested on Ubuntu 16.04 and xfce.

```
$ autoreconf
$ ./configure
$ make
# make install
```

Packages you may need to install to build this program:
- build-essential
- autoconf
- libxext-dev
- libxi-dev
- libglib2.0-dev

License
-------
Copyright (C) 2016 zunda <zundan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
