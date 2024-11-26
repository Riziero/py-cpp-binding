<h2>cpp and python lib using pybind11</h2>
This is a little project to showcase how to properly use pybind11 to generate a python module starting from a simple `cpp` project.
 It is by no means ready for production. It could be improved by having some sort of `CI` kick off the process, build and publish a wheel, package an `rpm` or `debian` and so fort.
<h3>How to run it</h3>

Build the docker image `pysort`
```
sudo docker build . --tag pysort
```
then run it with
```
sudo docker run -v ./out:/opt/out:Z -it pysort
```
<h3>what it does</h3>
- builds and tests the cpp library `sorting.so`  
- builds and tests the `pysort` python module  
- archives all the libs in a `.tgz` file  
- copies the artifacts in the `./out` folder for further processing  