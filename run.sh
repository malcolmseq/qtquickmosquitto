#!/bin/bash

DIRNAME=`dirname $0`
cd ${DIRNAME}
DIRNAME=`pwd`
echo ${DIRNAME}

qmlscene \
-I ./bin/ \
qml/index.qml
