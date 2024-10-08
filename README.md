# num-conv
This tool provides basic utilities for basic number system conversion and prints its processes

## Installation
### Installation 
Follow the steps below to perform a manual installation:
1. Clone the repository
    ```
    git clone https://github.com/Ultra8Gaming/num-conv.git
    ```
2. Generate cmake files
    ```
    cmake ./
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

## Testing
Testing executable is in the tests folder `num-conv-test`. Add extra tests by modifying CMakeLists.txt.

## Contributions
Contributions are welcome! Feel free to submit pull requests and open issues.
