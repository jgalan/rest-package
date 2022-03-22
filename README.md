
A dummy program to show how to compile an executable using ROOT and REST libraries.

If you got REST libraries running, i.e. after sourcing `/path/to/rest/install/thisREST.sh`, then just follow these steps to compile your REST project.

```
cd rest-package
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
make -j4 install
```

This will compile the `dummy` executable and place it at the `../install` directory. Just go to that directory and execute it:

```
cd ../install
./dummy
```

If you wish the executable to be accessible from anywhere else, just add it to the path system variable which in UNIX is usually `PATH`:

```
export PATH=$PATH:/path/to/dummy/install/
```

Remember to add the previous line to your `.bashrc` to be effective at each shell terminal initialization!

**This is a template repository** you may create your new GitHub repository using this one as a template https://github.com/rest-for-physics/rest-package
