#!/bin/bash

echo "Testing MCHB..."

./mchb_runner examples/hello.mchb

if [ $? -eq 0 ]; then
    echo "MCHB test passed!"
else
    echo "MCHB test failed!"
fi
