#include<iostream>
#include<string>
#include<vector>
#include<Memory>
using namespace std;

class Texture
{
    private:
        string name;
        int width ;
        int height;

    public:
    Texture(string n , int w , int h)
    {
        name=n;
        width =w;
        height = h;
        cout<<"Texture Loaded"<<endl;

        auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
    }
        ~Texture()
    {
         cout << "[Texture Released]" << endl;
    }
   void display() const{
    cout<<"Name: " << name << endl;
    cout<< "Width:" << width<< endl;
    cout <<"height"<<height << endl;
   }
};

int main(){
auto tex1 = make_unique<Texture> ("player_sprite", 512 ,512);
    tex1-> display();

    unique_ptr<Texture>tex2 =move(tex1);

    cout << (tex1 == nullptr ? "tex1 is null" : "tex1 is not null") << endl;
    tex2->display();
    return 0;
}