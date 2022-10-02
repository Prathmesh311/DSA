#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[][10], int m, int n, int i, int j){
    //Base case
    if(i == m && j == n){
        soln[i][j] = 1;
        //print path
        for(int x = 0; x <= m; x++){
            for(int y = 0; y <= n; y++){
                cout<<soln[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        return true;
    }

    //Rat should be inside grid
    if(i > m || j > n){
        return false;
    }

    //Checking if position is blocked
    if(maze[i][j] == 'X'){
        return false;
    }


    //Recursive case
    soln[i][j] = 1;

    bool right = ratInMaze(maze, soln, m, n, i, j+1);
    bool left = ratInMaze(maze, soln, m, n, i+1, j);

    //Backtracking
    soln[i][j] = 0;

    if(right || left){
        return true;
    }
    
    return false;
}


int main(){
   char maze[10][10] = {"0000",
                        "00X0",
                        "000X",
                        "0X00"};

    int soln[10][10] = {0};
    int m=4,  n=4;

    bool ans = ratInMaze(maze, soln, m-1, n-1, 0, 0);

    if(ans == false){
        cout<<"path is not present!";
    }
   
   
    return 0;
}