# Logic Simulator

## Course Assignment - EE 677 - Foundations of VLSI CAD

#### We can simulate any combinational circuit using this Logic Simulator

### Author: Rohan Rajesh Kalbag

Open `logic_simulator.ipynb` to see the code working in action, and access the code, relevant markdown documentation, for the **2X1 MUX** netlist example which is given at `/circuit.txt`

### Instructions to use the Logic Simulator

* Set up `Python 3.x`  virtual environment and use the command in terminal `pip install -r requirements.txt` to make sure you have all the required dependencies.
* If needed change the `/circuit.txt` in such a way as following the following netlist convention given after instructions
* Run the python script `logic_sim.py` using `python ./logic_sim.py` and find the output truth table in `truthtable.csv`

### Input Netlist Convention

#### We shall use `.txt` netlist file with a `NGSPICE` like style to describe the various components connected, to input the circuit configuration which we wish to simulate. This is an example

```spice

* this is a comment

* inp <nodes seperated by spaces> denotes input nodes to circuit

inp n1 n2 n4 n6


* outp <nodes seperated by spaces> denotes output nodes to circuit

outp n3 n5 n7


and n1 n2 n3

* denotes and gate with inputs n1 and n2, output as n3


or n3 n4 n5 

* denotes or gate with inputs n3 and n4, output as n5 


inv n6 n7

* denotes inverter with input n6 and output n7

```
