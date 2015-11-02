#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Wrong format, invoke: $0 <base-file-name>"
  exit 1
else
  FILE_NAME_BASE="$1"
fi

NAME_ITEMS=$(echo "${FILE_NAME_BASE}" | tr "-" "\n")
Arr=`echo "$(echo ${NAME_ITEMS} | sed 's/.*/\u&/')"`
STR_SMALL=`echo "$(echo ${FILE_NAME_BASE} | sed 's/-/_/g')"`

CLASS_NAME=""
for line in ${Arr}; do
  ITEM=`echo "$(echo ${line} | sed 's/.*/\u&/')"`
  CLASS_NAME+="${ITEM}"
done

STR_BIG=`echo "${STR_SMALL}" | tr "a-z" "A-Z"`

echo "Class name: ${CLASS_NAME}"
echo "Big-name: ${STR_BIG}"
echo "Small-name: ${STR_SMALL}"

HEADER_FILENAME="${FILE_NAME_BASE}.h"
SOURCE_FILENAME="${FILE_NAME_BASE}.c"

cp gtemplate.c "${SOURCE_FILENAME}"
cp gtemplate.h "${HEADER_FILENAME}"

sed  "s/gobj_template/${STR_SMALL}/g" --in-place ${HEADER_FILENAME}
sed  "s/gobj_template/${STR_SMALL}/g" --in-place ${SOURCE_FILENAME}

sed  "s/GOBJ_TEMPLATE/${STR_BIG}/g" --in-place ${HEADER_FILENAME}
sed  "s/GOBJ_TEMPLATE/${STR_BIG}/g" --in-place ${SOURCE_FILENAME}

sed  "s/GObjectTemplate/${CLASS_NAME}/g" --in-place ${HEADER_FILENAME}
sed  "s/GObjectTemplate/${CLASS_NAME}/g" --in-place ${SOURCE_FILENAME}
