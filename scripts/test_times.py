#!/usr/bin/env python2
"""
	kuroBox / naniBox
	Copyright (c) 2013
	david morris-oliveros // naniBox.com

    This file is part of kuroBox / naniBox.

    kuroBox / naniBox is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    kuroBox / naniBox is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

"""

import sys
import os

def add(a,b,ideal):
	a[0] += b[3] - ideal[0]
	a[1] += b[4] - ideal[1]
	a[2] += b[5] - ideal[2]

def check_times(fname):
	lines = file(fname).readlines()

	idx = 0
	running = [long(0) for i in range(3)]
	ideal = [168000000, 5600000, 168000000]
	for line in lines:
		line = line.strip()
		idx += 1
		nums = [long(i) for i in line.split(",")]
		add(running,nums,ideal)
		#print running

	print running
	print running[0]/idx
	print running[1]/idx
	print running[2]/idx


def main():
	for fname in sys.argv[1:]:
		check_times(fname)

if __name__ == '__main__':
	main()