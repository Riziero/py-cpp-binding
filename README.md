### What is this project about
A little project to showcase how to properly use pybind11 to generate a python module starting from a simple `cmake` project. 
It is by no means ready for production. It can be improved in many way for one by having 
some sort of `CI` kick off the process, build and publish a wheel.

The only requirments are that you have a working installation of `git` and `Docker`.

### How to run it
`git clone` this repo, `init` and `update` the submodules and build the `pysort` docker image 
```
git clone https://github.com/Riziero/py-cpp-binding.git

cd py-cpp-binding
git submodule --init
git submodule --update

docker build . --tag pysort
```
then run it with
```
docker run -v ./out:/opt/out:Z -it pysort
```
The code above has been tested on `Ubuntu24` (thorugh `wsl`). Since this is a `docker` 
based solution it should work just fine on `MacOS` and `Windows`. 
### What it does
* builds and tests the cpp library `sorting.so`  
* builds and tests the `pysort` python module  
* archives all the libs in a `.tgz` file  
* copies the artifacts in the `./out` folder for further processing  