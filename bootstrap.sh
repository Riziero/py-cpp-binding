set -ex

# Build the project
mkdir /src/build
cd /src/build
cmake ..
make

# RUN cpp tests...
/src/build/bin/testcpp 

# RUN py test...
cd /src/pytesting && pytest

# COpy our artifact so they live after the container dies
cp /src/build/*.tgz /opt/out
cp /src/build/lib/pysort*.so /opt/out

