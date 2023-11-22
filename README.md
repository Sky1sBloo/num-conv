# num-conv
This tool provides basic utilities for basic number system conversion and prints its processes

## Installation
### Installation for Windows users
1. Compile main.cpp using your preferred compiler

### Installation for Linux users
Follow the steps below to perform a manual installation:
1. Clone the repository with `https://github.com/Ultra8Gaming/num-conv.git`
3. Move to your PATH directory (can be `/usr/local/bin`, `/opt`, `~/.local/bin` or any specified PATHS)  
   `cd [path directory]`
5. Create a system link to your installed repository
   `ln -s [path to your repository]/num-conv num-conv`

Alternatively you can directly move *num-conv* using: `mv [path to repository/num-conv] [directory to PATH]`

## Usage
### --help
> Lists all commands 
### --dec2base [decima] [base] 
> Converts a decimal to radix with precision 8

### --dec2base [decimal] [base] -p [precision]
> Converts a decimal to radix with a specified precision

### --base2dec [value] [base]
> Converts a radix to decimal
