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
simple Txc4
{
    parameters:
        @display("i=block/routing");
        bool sendMessage = default(false);
        int limit = default(5);
        int delayTime = default(10);
    gates:
        input in;
        output out;
}

simple Txc4Child extends Txc4
{
    parameters: 
        @display("i=block/routing");
        sendMessage = true;
}
//
// TODO documentation
//
network Tictoc4
{
    submodules:
        tic: Txc4 {
            sendMessage = false;
            @display("p=66,56");
        }
        toc: Txc4 {
            sendMessage = false;
            @display("p=191,79");
        }
        servertictoc: Txc4Child {
            @display("p=116,157");
        }
    connections:
        servertictoc.out --> toc.in;
        toc.out --> tic.in;
        tic.out --> servertictoc.in;
}

