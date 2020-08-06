# @TEST-EXEC: zeek -NN Zeek::Netmap |sed -e 's/version.*)/version)/g' >output
# @TEST-EXEC: btest-diff output
