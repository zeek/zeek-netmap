# @TEST-EXEC: bro -NN Bro::Netmap |sed -e 's/version.*)/version)/g' >output
# @TEST-EXEC: btest-diff output
