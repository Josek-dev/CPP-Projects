class Object{
    private:
        static int num;
    public:
        Object(){++num;};
        Object(Object& object){++num;};
        ~Object(){--num;};
        static int count() {return num;}
};

int Object::num = 0;


#include <iostream>

int main(){
    Object object1;
    {
        Object object2(object1);
        std::cout << Object::count() << " ";
    }
    std::cout << Object::count() << std::endl;
}
