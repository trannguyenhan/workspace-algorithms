//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package _02enhancingtictoc;
simple Txc3
{
    parameters:
        @display("i=block/routing");
    gates:
        input in;
        output out;
}

//
// TODO documentation
//
network Tictoc3
{
    @display("bgb=298,175");
    types:
    submodules:
        tic: Txc3 {
            @display("i=,cyan;p=75.18,89.5");
        }
        toc: Txc3 {
            @display("i=,gold;p=196,88");
        }
    connections:
        tic.out --> {  delay = 100ms; } --> toc.in;
        toc.out --> {  delay = 100ms; } --> tic.in;
}

