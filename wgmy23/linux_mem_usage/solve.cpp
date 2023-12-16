#include <bits/stdc++.h>

using namespace std;

class Process {
    public:
        int pid;
        int ppid;
        int mem;
        int totalmem = 0;
        vector<Process*> children;

        Process(){
            pid = 0;
            ppid = 0;
            mem = 0;
        }

        Process(int a, int b, int c){
            pid = a;
            ppid = b;
            mem = c;
        }

        int memUsed(){
            if (totalmem != 0){
                // this has alr been calculated
                return totalmem;
            }

            int total = mem;
            for (Process* child : children){
                total += child->memUsed();
            }
            
            totalmem = total;
            return total;
        }
};

int main(){
    int n,q;
    cin >> n >> q;

    int a,b,c;
    unordered_map <int,Process*> hashmap;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        Process *current = new Process(a,b,c);
        hashmap.insert({a,current});

        if (b != 0)
            hashmap[b]->children.push_back(current);  
    }

    int pid;
    for (int i = 0; i < q; i++){
        cin >> pid;
        cout << hashmap[pid]->memUsed() << endl;
    }

    return 0;
}
