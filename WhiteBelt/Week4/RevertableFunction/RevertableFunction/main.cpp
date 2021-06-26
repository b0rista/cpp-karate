//
//  main.cpp
//  RevertableFunction
//
//  Created by Boris Tarovik on 26.06.2021.
//

#include <iostream>
#include <vector>

using namespace std;

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart {
public:
    FunctionPart(char newOperation, double newTerm) {
        operation = newOperation;
        term = newTerm;
    }
    double Apply(double x) const {
        if (operation == '+') {
            return x + term;
        }
        else if (operation == '-') {
            return x - term;
        }
        else if (operation == '*') {
            return x * term;
        }
        else if (operation == '/') {
            return x / term;
        }
        else {
            // not implemented yet
            return 0;
        }
    }
    void Invert() {
        if (operation == '+') {
            operation = '-';
        }
        else if (operation == '-') {
            operation = '+';
        }
        else if (operation == '*') {
            operation = '/';
        }
        else if (operation == '/') {
            operation = '*';
        }
    }
private:
    char operation;
    double term;
};

class Function {
public:
    void AddPart(char operation, double term) {
        operations.push_back({operation, term});
    }
    
    double Apply(double x) const {
        double result = x;
        for (const auto& op: operations) {
            result = op.Apply(result);
        }
        return result;
    }
    
    void Invert() {
        for (auto& op: operations) {
            op.Invert();
        }
        reverse(begin(operations), end(operations));
    }
private:
    vector<FunctionPart> operations;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
