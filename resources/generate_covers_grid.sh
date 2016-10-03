#!/bin/sh

SCRIPT_DIR=$( dirname "$( readlink --canonicalize "$0" )" )

# filenames with spaces handling nightmare
ls "${SCRIPT_DIR}"/../plugins/*/cover.jpg \
  | shuf \
  | sed -r "s/(.*)/'\1'/" \
  > /tmp/covers

montage @/tmp/covers \
  -tile 10 \
  -geometry 80x80 \
  "${SCRIPT_DIR}/../info/comics_covers.jpg"

rm -f /tmp/covers