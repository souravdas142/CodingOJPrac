
int search(vector<string>& vs,char ch) {
    int low = 2;
    int high = 9;
    int ans = 0;
    while(low<=high) {
        int mid = low+(high-low)/2;
        
        if( ch>= vs[mid][0] && ch <= vs[mid].back()) {
            ans = mid;
            break;
        }
        else if(ch>vs[mid].back()) {
            low = mid+1;
        }
        else if(ch<vs[mid].front()) {
            high = mid-1;
        }
        
        
        
    }  
    return ans;
    
}

string printSequence(string s) {
    // code here.
    vector<string> vs = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
    int n = s.size();
    int i = 0;
    string ans = "";
    while(i<n) {
        if(s[i]==' ') {
            ans+='0';
            i++;
            continue;
        }
        int x = search(vs,s[i]);
        char ch = '0'+x;
        //cout<<"char = "<<ch<<endl;
        //cout<<"times = "<<(s[i]-vs[x][0])+1<<endl;
        ans+=string((s[i]-vs[x][0])+1,ch);
        i++;
    }
    
    return ans;

}