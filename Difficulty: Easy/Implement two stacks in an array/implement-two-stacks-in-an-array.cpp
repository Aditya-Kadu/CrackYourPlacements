//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks {
  public:
    vector<int> v;
    int ind1;
    int ind2;

    twoStacks() {
        v.resize(200);
        ind1 = 99;
        ind2 = 100;
    }

    void push1(int x) {
        if (ind1 >= 0 && ind1 <= ind2 - 1) {
            v[ind1] = x;
            ind1--;
        }
    }

    void push2(int x) {
        if (ind2 < v.size() && ind2 >= ind1 + 1) { 
            v[ind2] = x;
            ind2++;
        }
    }

    int pop1() {
        if (ind1 < 99) {
            int temp = v[ind1 + 1];
            ind1++;
            return temp;
        }
        return -1; 
    }

    int pop2() {
        if (ind2 > 100) {
            int temp = v[ind2 - 1];
            ind2--;
            return temp;
        }
        return -1; 
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends