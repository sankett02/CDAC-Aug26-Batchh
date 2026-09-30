#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    int R,C;

    cout<<"Enter number of rows: ";
    cin>>R;

    cout<<"Enter number of columns:";
    cin>>C;

    //Allocate outer array of rows pointers
    int** map = new int*[R];

    //Allocate each row
    for(int i = 0; i < R; i++){
    map[i] = new int[C];

    //Send random number generator
    srand(time(0));

     // Fill the map with random tile values 0-4
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = rand() % 5;
        }
    }

        // Counters for each tile
    int grass = 0;
    int water = 0;
    int mountain = 0;
    int forest = 0;
    int dungeon = 0;

     // Display map and count tiles
    cout << "\nGame Map:\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            cout << map[i][j] << " ";

            if (map[i][j] == 0)
                grass++;
            else if (map[i][j] == 1)
                water++;
            else if (map[i][j] == 2)
                mountain++;
            else if (map[i][j] == 3)
                forest++;
            else if (map[i][j] == 4)
                dungeon++;
        }

        cout << endl;
    }

     // Legend
    cout << "\nLegend:\n";
    cout << "0 = Grass\n";
    cout << "1 = Water\n";
    cout << "2 = Mountain\n";
    cout << "3 = Forest\n";
    cout << "4 = Dungeon\n";

    // Tile counts
    cout << "\nTile Counts:\n";
    cout << "Grass: " << grass << endl;
    cout << "Water: " << water << endl;
    cout << "Mountain: " << mountain << endl;
    cout << "Forest: " << forest << endl;
    cout << "Dungeon: " << dungeon << endl;

    // Deallocate each row
    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }

    // Deallocate outer array
    delete[] map;

    return 0;
    }
}