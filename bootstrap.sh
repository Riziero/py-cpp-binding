set -ex

# ls -ll /src

mkdir /src/build
cd /src/build
cmake ..
make

# RUN cpp test
/src/build/bin/testcpp 

# RUN py test
cd /src/pytesting && pytest
