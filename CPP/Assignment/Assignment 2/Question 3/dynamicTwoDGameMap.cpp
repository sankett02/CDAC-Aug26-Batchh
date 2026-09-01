#include <iostream>
using namespace std;

class Map{
    private:
        int row;
        int col;
        int count[5];
        int **arr;
    public:
        Map():count{}{
        }
        void setRow(){
            cout<<"Enter number of rows: ";
            cin>>row;
            while(row <= 0){
                cout<<"Invalid number of rows"<<endl;
                cin>>row;
            }
        }
        void setCol(){
            cout<<"Enter number of cols: ";
            cin>>col;
            if(col <= 0){
                cout<<"Invalid number of cols"<<endl;
                setCol();
            }
        }
        void makeMap(){
            arr = new int*[row];
            int temp;
            for(int i=0; i<row; i++){
                arr[i] = new int[col];
                for(int j=0; j<col; j++){
                    temp = rand() % 5;
                    count[temp]++;
                    arr[i][j] = temp;
                }
            }
        }
        void displayMap(){
            cout<<"===== GAME MAP ("<<row<<" X "<<col<<") ====="<<endl;
            for(int i=0; i<row; i++){
                for(int j=0; j<col; j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<"Legend: 0=Grass  1=Water  2=Mountain 3=Forest 4=Dungeon"<<endl;
            cout<<endl;
            cout<<"Tile Count:"<<endl;
            cout<<"  Grass    : "<<count[0]<<endl;
            cout<<"  Water    : "<<count[1]<<endl;
            cout<<"  Mountain    : "<<count[2]<<endl;
            cout<<"  Forest    : "<<count[3]<<endl;
            cout<<"  Dungeon    : "<<count[4]<<endl;
        }
        ~Map(){
            for(int i=0; i<row; i++){
                delete[] arr[i];
            }
            delete[] arr;
        }
};

int main(){
    Map obj1;
    obj1.setRow();
    obj1.setCol();
    obj1.makeMap();
    obj1.displayMap();

    return 0;
}