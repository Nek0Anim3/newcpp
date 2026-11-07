# CGEN - Template project generator
 Used for quick C/C++ project creation, w/ or without CMake config.
Currently doesn't have flags, configs are hardcoded kinda..

## Usage: 
`> cgen`
Then follow steps in terminal.  
1) Give a name to project.
2) Select language C or C++
3) Specify a directory (or leave blank to use current working directory)
4) Use CMake (0 / 1) ?  
Then program will give you a quick instructions like
```
PROJECT 'example' CREATED

Navigate --  cd /home/user/example

---- Build with CMake ----

1)    cd /home/user/example/build
2)    cmake ..
3)    cmake --build .
4)    ./example
```

## Compiling and using
### 1) Requirements
Ensure you have CMake, Ninja/Make and GCC installed.
If not, use internet to find out how to install these packages on your system.  
### 2) Cloning and building
Clone repository 
`> git clone https://github.com/Nek0Anim3/newcpp`  
  
  Create build/ folder and change to it
  `> cd newcpp`
  `> mkdir build`
  `> cd build`  
    
   Generate config and compile program
   `> cmake ..`
   `> cmake --build .`

(Optionally) You can test program by running it 
`> ./cgen`

### 3) Linking globally in system
To link executable and run it from anywhere, use ln with sudo
`> sudo ln -s /path/to/folder/cgen /usr/local/bin/cgen`

Now you can run it anywhere in system




