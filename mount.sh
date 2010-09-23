#!/bin/sh
# Created @ 12.10.2009 by TheFox@fox21.at

if (mount | grep floppy); then
	echo "umount failed"
else
	echo "umount ok"
fi

# EOF

