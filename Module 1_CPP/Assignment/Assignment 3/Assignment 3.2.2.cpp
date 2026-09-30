#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Shader
{
private:
    string name;
    string type;

public:
    Shader(string n, string t)
    {
        name = n;
        type = t;
        cout << "[Shader Compiled]" << endl;
    }

    ~Shader()
    {
        cout << "[Shader Destroyed]" << endl;
    }

    int getReferenceCount(const shared_ptr<Shader>& ptr) const
    {
        return ptr.use_count();
    }
};

int main()
{
    auto shader = make_shared<Shader>("main_vert", "vertex");

    cout << "Ref count: " << shader->getReferenceCount(shader) << endl;

    {
        auto rendererRef = shader;
        cout << "Ref count: " << shader->getReferenceCount(shader) << endl;

        auto editorRef = shader;
        cout << "Ref count: " << shader->getReferenceCount(shader) << endl;
    }

    cout << "Ref count: " << shader->getReferenceCount(shader) << endl;

    return 0;
}