#!/bin/bash
echo "run test!"
export MV_STATE_YAML=../config/config.yaml
./yaml-test
#or
#./yaml-test ../config/config.yaml