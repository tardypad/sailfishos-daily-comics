#!/bin/sh

SCRIPT_DIR=$( dirname "$( readlink --canonicalize "$0" )" )

# retrieve the plugins name and order them
# ignoring some prefixes
grep -r '"name"' "${SCRIPT_DIR}"/../plugins/ \
  | sed -r 's/.*"name": "([^"]*)".*/\1/' \
  | sed -r 's/^(The|Le|Une) (.*)/\2, \1/' \
  | sort \
  | sed -r 's/(.*), (The|Le|Une)$/\2 \1/' \
  > "${SCRIPT_DIR}/../info/comics_list.md"

# prepend - to each line to create the list
sed -i -e 's/^/- /' "${SCRIPT_DIR}/../info/comics_list.md"
