#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int a;
    cin >> a;

    for(int i = 0; i<a; i++)
    {
        deque<int> dq;
            
        int n,m;
        cin >> n >> m;
        int rec = 0;
        
        for(int j=0;j<n;j++)
        {
            int temp; cin >> temp;
            dq.push_back(temp); //
        }
        
        auto maxDqElement = max_element(dq.begin(), dq.end());
        
        for(;rec<dq.size();rec++)
        {
            if(*maxDqElement == dq[rec]) break;
        }
        
        
        cout << rec << '\n';
       
    }
    
}
