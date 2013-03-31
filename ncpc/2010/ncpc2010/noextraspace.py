#!/usr/bin/python

from sys import stdin, exit

using_rn = False

for line in stdin:
    if line[-2] == '\r' and line[-1] == '\n':
        BR = '\r\n'
        using_rn = True
    else:
        BR = '\n'
    line2 = ' '.join(line.strip().split()) + BR
#     if line[-1] != '\n':
#         print 'Final line missing end of line character'
    if line != line2:
        print 'Extra space in: "%s"' % line
        exit(13)
    if line.strip() == '':
        print 'Empty line'
        exit(14)


if using_rn:
    print 'WARNING: Using Windows linebreaks'
    exit(15)
