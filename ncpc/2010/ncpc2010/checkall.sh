#!/bin/bash

PROBLEMS="add-help borg connect gameshow succession skyline roundtrip driving statisticians polyomino doodle"

for p in $PROBLEMS; do
  echo Checking $p;
  for i in $p/$p.*.inex $p/$p.*.in $p/data/*.in; do
    if [ -e $i ]; then
      o=${i/.in/.ans};
      o=${o/.ansex/.outex};
      echo "    $i -- $o";
      c=$p/${p}_check.py;
      if [ -e $o ]; then 
        if [ -e $c ]; then
          python $c < $i || echo Error checking $i;
#         else
#           echo MISSING: $c;
        fi
        for x in $i $o; do
          python noextraspace.py < $x || echo White-space problems in $x
        done
      else 
        echo MISSING: $o;
      fi
    fi
  done
done
