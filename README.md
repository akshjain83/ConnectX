[![Build Status](https://travis-ci.org/akshjain83/ConnectX.svg?branch=master)](https://travis-ci.org/akshjain83/ConnectX) [![Coverage Status](https://coveralls.io/repos/github/akshjain83/ConnectX/badge.svg?branch=master)](https://coveralls.io/github/akshjain83/ConnectX?branch=master)

[Akshay Jain](https://github.com/akshjain83)

#Bugs
* Bug 1 - 
For the function, bool ConnectX::inBounds(int w, int h), as stated in its documentation header that it should return whether or not the provided location is a valid space in the board. This function doesn't returns the correct ouput for certain provided locations. If the values passed to this function have invalid width, i.e. , value of w is invalid, but valid height then this function should return false(invalid). Instead this function still return true as it uses same bool flag/variable(here name 'inside'). This bug affects the other functions(Piece at(int,int), void placePiece(int)), eventually causing the whole program to malfunction. Either height and weight should be checked together or used two different flags(bool variables) or another correct logical implemention should be developed to fix this bug.

* Bug 2 -
Uncertain about this bug, but when instantiating the object of class ConnectX with certain positive values where value of x(toWin) is a positive value much larger(greater than width x height), then the constructor still keeps the same values, even though the x(toWin) or number of space required to win the game is not possible to achieve. So x should not only greater than 0, but it should be less than or equal to (width X height).


* Bug 3 -
Another bug(most likely its a bug, uncertain if its a logical error), is caused in void placePiece(int) function due to inBounds() function. The false coverage in the if condition is not possible, stated as follows,
if( at(column,i) == EMPTY && inBounds(column,i) )

in above condition, we can never get false for inBounds(column,i) since we are already checking that within the preceding condition, at(column,i) == EMPTY, if this is false then it doesn't matter but when it is true then the succeeding condition will 
