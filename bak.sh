#!/bin/sh
# Created @ 12.10.2009 by TheFox@fox21.at

NEWFILE="backup_`date +"%Y-%m-%d_%H-%M-%S"`.tar.gz"
if [ "x$1" != "x" ] && [ -f $1 ]; then
	MMV="mv $1 $NEWFILE"
	echo $MMV
	$MMV
	chmod 600 $NEWFILE
fi

# EOF
