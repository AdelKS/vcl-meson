#include <cmath>
#include <vcl/vectorclass.h>

// test adapted from Example 10.6 of the vcl manual

const double pi=3.14159265358979323846;

//length of table. Must be a power of 2.
#define sin_tablelen 1024
//the accuracy of table lookup is +/- pi/sin_tablelen

class SinTable {
protected:
    float table[sin_tablelen];
    float resolution;
    float rres;//1./resolution
public:
    SinTable();//constructor
    Vec4f sin(Vec4f x);
    Vec4f cos(Vec4f x);
};

SinTable::SinTable() {  //constructor
    //computeresolution
    resolution = float(2.0 * pi / sin_tablelen);
    rres = 1.0f / resolution;
    //Initialize table(No need to use vectors here because this
    //is calculated only once: )
    for(int i = 0 ; i < sin_tablelen ; i++) {
        table[i] = sinf((float)i * resolution);
    }
}

Vec4f SinTable::sin(Vec4f x) {
    //calculate sin by table lookup
    Vec4i index = roundi(x * rres);
    //modulo tablelen equivalent to modulo 2*pi
    index &= sin_tablelen - 1;
    //lookup in table
    return lookup<sin_tablelen>(index, table);
}

Vec4f SinTable::cos(Vec4f x){
    //calculate cos by table lookup
    Vec4i index = roundi(x * rres) + sin_tablelen/4;
    //modulo tablelen equivalent to modulo 2*pi
    index &= sin_tablelen - 1;
    //lookup in table
    return lookup<sin_tablelen>(index, table);
}

int main() {
    SinTable sintab;

    Vec4f a(0.0f, 0.5f, 1.0f, 1.5f);
    Vec4f b = sintab.sin(a);

    // expected result
    Vec4f c(0.0000f, 0.4768f, 0.8416f, 0.9973f);

    // accuracy should be: +/- 0.003
    bool test_fails = horizontal_or(abs(b - c) > 0.003);

    return test_fails;
}