# roll

A simple program to roll dice for dnd\

## About

Roll any number of dice and add a modifier
Born out of a spur-of-the moment idea and implemented late at night :)

## Installation
- Clone the repo using `git clone https://github.com/The5thAxiom/roll`
- Build the project using `make`
- Roll away!

## Usage

### Flags
- `-n`: the number of dice to roll, default is 1
- `-d`: the number of faces of the dice to roll, default is 20
- `-a`: the number to be added after the roll
- `-A`: rolls the dice with advantage (rolls twice and takes the greater roll)
- `-D`: rolls the dice with disadvantage (rolls twice and takes the lesser roll)

eg: `./roll -n 3 -d 20 -a 4`, will roll 3 twenty-sided die and add 4 to the answer
eg: `./roll -d 20 -a 5 -A`, will roll a twenty-sided with advantage die and add 5 to the answer

## String
The `-n`, `-d` and `-a` flags can be omitted by using a string representation of the form: `[n]d[d]+[a]`.
Examples:
- `./roll 3d20+4` will roll 3 twenty-sided die and add 4 to the answer
- `./roll d10+2 -D` will roll a ten-sided die with disadvantage and add 2 to the result 


## License
Released under the GNU GPL-3.0 license. This is Free and Open Source Software.