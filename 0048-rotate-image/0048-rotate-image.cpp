
ostream& operator<<(ostream& print, vector<vector<int> >& mat) {
    for(auto vvec:mat) {
        for(auto vec:vvec ) {
            print<<vec<<" ";
        }
        print<<"\n";
    }
    return print;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //cout<<"original\n"<<matrix<<endl;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0;i<row;i++) {
            for(int j = i+1;j<col;j++) {
                if(i==j) continue;
                swap(matrix[i][j],matrix[j][i]);
                //cout<<matrix<<endl;
            }
        }
        //cout<<endl;
        //cout<<"Transpose\n"<<matrix<<endl<<endl;
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                int revcol = col-1-j;
                if(j>=revcol) break;
                swap(matrix[i][j],matrix[i][revcol]);
            }
        }
        //cout<<endl;
        //cout<<"90 rotate\n"<<matrix<<endl<<endl;
    }
};