# num-conv
This tool provides basic utilities for basic number system conversion and prints its processes

## Installation
### Installation for Windows users
1. Clone the repository or download zip.
    ```
    git clone https://github.com/Ultra8Gaming/num-conv.git
    ```
2. Extract the zip file (if applicable).
3. Open the folder where you extracted/cloned the repository.
4. Right click, click **Open in Terminal** (if you're using Windows 11 and its missing, press **Show more options**)
5. You can run the program by typing `num-conv.exe [COMMAND]` in the terminal. You can see the commands below or type `num-conv.exe --help` in the console.


>Notes
>If **Open in Terminal** is missing in the context menu, you can:
>1. Open the command prompt
>2. Type cd "directory to your file"
>```
>ex. cd C:\users\[USER]\desktop\num-conv
>```

### Installation for Linux users
Follow the steps below to perform a manual installation:
1. Clone the repository
    ```
    git clone https://github.com/Ultra8Gaming/num-conv.git
    ```
2. Go to the *build-linux* directory
    ```
    cd build-linux
    ```
3. Compile and install
    ```
    make
    sudo make install
    ```
> You can change installation location by modifying  CMakeLists.txt


## Usage
### Help
```
--help
```
Lists all commands
### Print operations
```
--print [conversion] ...
```
A modifier of printing the operations during the conversion processes 
### Decimal to base
```
--dec2base [decimal] [base]
```
Converts a decimal to radix with precision 8
```
--dec2base [decimal] [base] -p [precision]
```
Converts a decimal to radix with a specified precision

### Base to decimal
```
--base2dec [value] [base]
```
Converts a specified radix to decimal

### Binary to base
```
--binary2base [value] [base]
```
Does a direct connection from binary to the specified radix

### Base to binary
```
--base2binary [value] [base]
```
Does a conversion between from base to binary

## Contributions
Contributions are welcome! Feel free to submit pull requests and open issues.
