#include <bits/stdc++.h>
using namespace std;

class notgate{
    int id;
    int a,y;
public:    
    notgate(int p){
        id = p;
    }
    
    int evaluate(){
        if(a==1){
            y = 0;
        }
        else{
            y = 1;
        }
        return y;
    }

    void connect(int x){
        a = x;
    }
};

class andgate{
    int id;
    int a,b,y;
public:
    andgate(int p){
        id = p;
    }

    int evaluate(){
        if(a==1 && b==1){
            y = 1;
        }
        else{
            y = 0;
        }
        return y;
    }

    void connect_a(int x){
        a = x;
    }

    void connect_b(int x){
        b = x;
    }
};

class orgate{
    int id;
    int a,b,y;
public:
    orgate(int p){
        id = p;
    }

    int evaluate(){
        if(a==0 && b==0){
            y = 0;
        }
        else{
            y = 1;
        }
        return y;
    }

    void connect_a(int x){
        a = x;
    }

    void connect_b(int x){
        b = x;
    }
};

struct connection{
    char type1;
    char type2;
    int id1;
    int id2; 
    int p2;

    connection(char c1, char c2, int t1, int t2, int p){
        type1 = c1;
        type2 = c2;
        id1 = t1;
        id2 = t2;
        p2 = p;
    }    
};

class circuit{    
    vector<andgate*> andgates;
    vector<orgate*> orgates;
    vector<notgate*> notgates;
    int n0, n1, n2;
    vector<connection*> connections;    
    int no_of_inputs;
    vector<int> input_vector;
    int no_of_outputs;
    vector<int> output_vector;

public:
    circuit(int inps, int outps, int a, int o, int n){
        no_of_inputs = inps;
        no_of_outputs = outps;
        n0 = a;
        n1 = o;
        n2 = n;
        input_vector.resize(inps);
        output_vector.resize(outps);
    }

    void get_connections(int m){
        //m number of connections
        connections.resize(m); //adjacency list
        connections[0] = new connection('a','a',0,2,0);
        connections[1] = new connection('a','n',1,0,0);
        connections[2] = new connection('n','a',0,2,1);
    }

    void get_inputs(){
        std::cout<<"Enter Inputs"<<'\n';
        for(int i=0;i<no_of_inputs;i++){
            cin>>input_vector[i];
        }
    }

    void simulate(){
        for(int i=0;i<n0;i++){
            andgate* m = new andgate(i);
            andgates.push_back(m);
        }

        for(int i=0;i<n1;i++){
            orgate* m = new orgate(i);
            orgates.push_back(m);
        }

        for(int i=0;i<n2;i++){
            notgate* m = new notgate(i);
            notgates.push_back(m);
        }
        
        //input connections 
        andgates[0]->connect_a(input_vector[0]);
        andgates[0]->connect_b(input_vector[1]);
        andgates[1]->connect_a(input_vector[2]);
        andgates[1]->connect_b(input_vector[3]);

        for(auto p: connections){
            int val;
            if(p->type1 == 'a'){
                andgate* outp_gate = andgates[p->id1];
                val = outp_gate->evaluate();
            }
            else if(p->type1 == 'o'){
                orgate* outp_gate = orgates[p->id1];
                val = outp_gate->evaluate();
            }
            else{
                notgate* outp_gate = notgates[p->id1];
                val = outp_gate->evaluate();
            }

            if(p->type2 == 'a'){
                andgate* inp_gate = andgates[p->id2];
                if(p->p2 == 0){
                    inp_gate->connect_a(val);
                }
                else{
                    inp_gate->connect_b(val);
                }
            }
            else if(p->type2 == 'o'){
                orgate* inp_gate = orgates[p->id2];
                if(p->p2 == 0){
                    inp_gate->connect_a(val);
                }
                else{
                    inp_gate->connect_b(val);
                }
            }
            else{
                notgate* inp_gate = notgates[p->id2];
                inp_gate->connect(val);
            }
        }
        //output
        std::cout<<"Logic Output"<<'\n';
        output_vector[0] = andgates[2]->evaluate();
        std::cout<<output_vector[0]<<endl; 
    }
};

int main(){
    circuit c1(4, 1, 3, 0, 1);
    c1.get_connections(3);
    c1.get_inputs();
    c1.simulate();
}