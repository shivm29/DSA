int determinantOfMatrix(vector<vector<int> > matrix, int n)
{
    if(n == 1) return matrix[0][0];
    int ans = 0;
    
    // traversing all elements of first row : 
    for(int i=0; i<n; i++) {
        
        vector<vector<int>> child_matrix(n-1, vector<int>(n-1));
        // traversing remaining rows : 
        for(int j=1; j<n; j++) {
            int x = 0;
            
            // traversing columns
            for(int k=0; k<n; k++) {
                if(k == i) continue;
                
                child_matrix[j-1][x++] = matrix[j][k];
            }
        }
        
            ans += matrix[0][i]*determinantOfMatrix(child_matrix, n-1)*((i&1)?-1:1);
    }
    
    return ans;
    
}