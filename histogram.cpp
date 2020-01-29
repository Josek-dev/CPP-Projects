#include <cstdlib>
#include <cstring>
#include <iostream>

class Histogram{
    private:
        double *bins;
        int *height;
        int numBins;
        double maxValue;
    public:
        void allocateMemory(int numBins);
        Histogram();
        Histogram(Histogram &histogram);
        Histogram(double start, double stop, int numberOfBins);
        ~Histogram();
        Histogram& operator=(const Histogram& histogram);
        int operator[](int index) const;
        int size() const;
        Histogram& insert(double number);
};

void Histogram::allocateMemory(int numBins){
    bins = (double*)malloc(numBins * sizeof(double));
    height = (int*)malloc(numBins * sizeof(int));
}

Histogram::Histogram(){
    numBins = 0;
    maxValue = 0;
    allocateMemory(numBins);
}

Histogram::Histogram(Histogram &histogram){
    numBins = histogram.numBins;
    maxValue = histogram.maxValue;
    allocateMemory(numBins);
    for(int i = 0; i < numBins; i++){
        *(bins + i) = *(histogram.bins + i);
        *(height + i) = *(histogram.height + i);
    }
}

Histogram::Histogram(double start, double stop, int numberOfBins){
    numBins = numberOfBins;
    maxValue = stop;
    allocateMemory(numBins);

    double step = (stop - start) / (double)numBins;

    for(int i = 0; i < numBins; i++){
        *(bins + i) = start + step * i;
        *(height + i) = 0;
    }
}

Histogram::~Histogram(){
    numBins = 0;
    maxValue = 0;
    delete []bins;
    delete []height;

    bins = nullptr;
    height = nullptr;
}

Histogram& Histogram::operator=(const Histogram& histogram){
    numBins = histogram.numBins;
    maxValue = histogram.maxValue;
    allocateMemory(numBins);

    for(int i = 0; i < numBins; i++){
        *(bins + i) = *(histogram.bins + i);
        *(height + i) = *(histogram.height + i);
    }

    return *this;
}

int Histogram::operator[](int index) const{
    return *(height+index);
}

int Histogram::size() const{
    return numBins;
}

Histogram& Histogram::insert(double number){
    for(int i = 0; i < numBins; i++){
        if(number > maxValue || number < *bins){
            return *this;
        }
        else if(number >= *(bins+numBins-1) && number <= maxValue){
            *(height+numBins-1) += 1;
            return *this;
        }
        else if(number >= *(bins+i) && number < *(bins+i+1)){
            *(height+i) += 1;
            return *this;
        }
    }
}



std::ostream &operator <<(std::ostream &stream, const Histogram &histogram){
    for(int index = 0; index < histogram.size();){
        stream << histogram[index++] << " ";
    }
    return stream;
}

int main(){
    Histogram histogram1(-15.2, 10.7, 10), histogram2;

    histogram1.insert(-100);
    histogram1.insert(0);
    histogram1.insert(18);
    histogram1.insert(-7);
    histogram1.insert(-7);
    histogram1.insert(-12);
    histogram1.insert(-7);
    histogram1.insert(0.17);
    histogram1.insert(0.75);
    histogram1.insert(0.33);
    histogram1.insert(21);
    histogram1.insert(10.5);
    histogram1.insert(7.8);
    histogram1.insert(7.8);
    histogram1.insert(0);
    histogram1.insert(5.3);
    histogram1.insert(-5.3);
    histogram1.insert(5.3);
    histogram1.insert(0.7);
    histogram1.insert(0.7);
    histogram1.insert(0);
    histogram1.insert(5.3);
    histogram1.insert(-5.3);
    histogram1.insert(5.3);
    histogram1.insert(-12);
    histogram1.insert(-7);
    histogram1.insert(0.17);
    histogram1.insert(0.75);
    histogram1.insert(-15.1);
    histogram1.insert(-13.2);

    std::cout << histogram1 << std::endl;
}
