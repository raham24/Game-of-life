#include <iostream>
using namespace std;

unsigned int next_generation(bool* A, bool* B, int rows, int columns){
	
	const int8_t DX[] = {0,1,1,1,0,-1,-1,-1};
	const int8_t DY[] = {-1,-1,0,1,1,1,0,-1};

	int changes = 0;
	for (int y=0; y<rows; y++){
    	for (int x=0; x<columns; x++){
    		int alive = 0;
    		int current_cell = A[y*columns+x];
        	for(int i=0; i<8; i++){
          		int ny = y+DY[i];
          		int nx = x+DX[i];
          		if (ny >= 0 && ny < rows && nx >= 0 && nx <= columns){
            		if (A[ny*columns+nx]) alive++;
            	}
    		}// end for i

    		B[y*columns+x] = current_cell;

    		if (alive == 3 && current_cell == false){B[y*columns+x]= true;changes++;}
        	if ((alive < 2 || alive > 3) && current_cell == true){B[y*columns+x]= false;changes++;}
    	}// end for x
    }// end for y
    return changes;
	
}
// 	int cycle_changes = 0;
// 	for (int y=0; y<rows; y++){
// 		for (int x=0; x<rows;x++){
			
// 			int changes=0;
// 			for(int i=0; i<8; i++){
// 				int ny = y+DY[i];
// 				int nx = x+DX[i];
// 				int alive = 0;
// 				if (ny>=0 && ny < rows && nx>=0 && nx<=columns){
// 					if(A[ny*columns*nx] = 1 ) alive +=1;
// 				}// end of ny/nx if
// 			if (alive == 3 && A[y*columns+x]) {B[y*columns+x]=1;changes+=1;}
// 			if (alive<2 || alive>3)
// 				if (A[y*columns+x]){B[y*columns+x]=0;changes+=1;}
// 			cycle_changes = changes;
// 			// bool* temp = A; A = B; B = temp;
// 			}// end of i
//       }// end of x
// 	}// end of y
// 	return cycle_changes;

// }
