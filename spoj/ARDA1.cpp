// Aho Corasick algorithm for string matching
using namespace std;
#include <bits/stdc++.h>
 
// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 90004;
 
// Maximum number of characters in input alphabet
const int MAXC = 26;
 
// Bit i in this mask is one if the word with index i
// appears when the machine enters this state.
int out[MAXS];
 
// FAILURE FUNCTION IS IMPLEMENTED USING f[]
int f[MAXS];
 
// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING g[][]
int g[MAXS][MAXC];
 
// Builds the string matching machine.
// arr -   array of words. The index of each keyword is important:
//         "out[state] & (1 << i)" is > 0 if we just found word[i]
//         in the text.
// Returns the number of states that the built machine has.
// States are numbered 0 up to the return value - 1, inclusive.
int buildMatchingMachine(string arr[], int k)
{
    // Initialize all values in output function as 0.
    memset(out, 0, sizeof out);
 
    // Initialize all values in goto function as -1.
    memset(g, -1, sizeof g);
 
    // Initially, we just have the 0 state
    int states = 1;
 
    // Construct values for goto function, i.e., fill g[][]
    // This is same as building a Trie for arr[]
    for (int i = 0; i < k; ++i)
    {
        const string &word = arr[i];
        int currentState = 0;
 
        // Insert all characters of current word in arr[]
        for (int j = 0; j < word.size(); ++j)
        {
            int ch = word[j] - 'a';
 
            // Allocate a new node (create a new state) if a
            // node for ch doesn't exist.
            if (g[currentState][ch] == -1)
                g[currentState][ch] = states++;
 
            currentState = g[currentState][ch];
        }
 
        // Add current word in output function
        out[currentState] |= (1 << i);
    }
 
    // For all characters which don't have an edge from
    // root (or state 0) in Trie, add a goto edge to state
    // 0 itself
    for (int ch = 0; ch < MAXC; ++ch)
        if (g[0][ch] == -1)
            g[0][ch] = 0;
 
    // Now, let's build the failure function
 
    // Initialize values in fail function
    memset(f, -1, sizeof f);
 
    // Failure function is computed in breadth first order
    // using a queue
    queue<int> q;
 
     // Iterate over every possible input
    for (int ch = 0; ch < MAXC; ++ch)
    {
        // All nodes of depth 1 have failure function value
        // as 0. For example, in above diagram we move to 0
        // from states 1 and 3.
        if (g[0][ch] != 0)
        {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
 
    // Now queue has states 1 and 3
    while (q.size())
    {
        // Remove the front state from queue
        int state = q.front();
        q.pop();
 
        // For the removed state, find failure function for
        // all those characters for which goto function is
        // not defined.
        for (int ch = 0; ch <= MAXC; ++ch)
        {
            // If goto function is defined for character 'ch'
            // and 'state'
            if (g[state][ch] != -1)
            {
                // Find failure state of removed state
                int failure = f[state];
 
                // Find the deepest node labeled by proper
                // suffix of string from root to current
                // state.
                while (g[failure][ch] == -1)
                      failure = f[failure];
 
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
 
                // Merge output values
                out[g[state][ch]] |= out[failure];
 
                // Insert the next level node (of Trie) in Queue
                q.push(g[state][ch]);
            }
        }
    }
 
    return states;
}
 
// Returns the next state the machine will transition to using goto
// and failure functions.
// currentState - The current state of the machine. Must be between
//                0 and the number of states - 1, inclusive.
// nextInput - The next character that enters into the machine.
int findNextState(int currentState, char nextInput)
{
    cout<<"hello"<<currentState;
    int answer = currentState;
    int ch = nextInput - 'a';
 
 	cout<<"hello"<<ch;
    // If goto is not defined, use failure function
    while (g[answer][ch] == -1){
        answer = f[answer];
    }
 
    return g[answer][ch];
}

set<int> ulc[2003][2003];
int m1,m2;
void searchPatterns(string arr[], int k, string text[])
{
	// Preprocess patterns
	buildMatchingMachine(arr,k);
	int currentState = 0;


	//Traversing the text to find occurrences of the pattern
	for(int i=0;i<m1;++i)
	{
		//currentState = 0;
		cout<<"1"<<endl;
		for(int j=0;j<text[i].size();++j)
		{
			cout<<currentState<<" "<<text[i][j]<<endl;
			currentState = findNextState(currentState,text[i][j]);

			//Match not found
			cout<<"2"<<endl;
			if(out[currentState] == 0)
				continue;
			cout<<"3"<<endl;
			//Match found
			for(int x=0;x<k;++x)
			{
				cout<<"4"<<endl;
				if(out[currentState] & (1<<x))
				{
					cout<<"5"<<endl;
					//Word arr[x] appears from j-arr[x].size()+1 to j in text[i]
					cout << "Word " << arr[x] << " appears from "
                     << j - arr[x].size() + 1 << " to " << j << endl<<" in "<<text[i]<<endl;
					ulc[i][j].insert(x);
				}
			}
			
		}
		
	}
	cout<<"over"<<endl;
	set<int>::iterator it;
	for(int i=0;i<m1;++i)
	{
		for(int j=0;j<m2;++j)
		{
			
			for(it=ulc[i][j].begin();it!=ulc[i][j].end();++it)
			{
				cout<<i<<" "<<j<<" "<<*it<<" ";
			}
			cout<<endl;
		}
	}
}

int main()
{
	int n1,n2;
	ios::sync_with_stdio(false);
	cin>>n1>>n2;
	string patterns[302],text[2003];
	for(int i=0;i<n1;++i)
	{
		cin>>patterns[i];
	}
	cin>>m1>>m2;
	for(int i=0;i<m1;++i)
	{
		cin>>text[i];
	}

	searchPatterns(patterns,n1,text);
}