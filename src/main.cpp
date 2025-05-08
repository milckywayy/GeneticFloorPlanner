#include <iostream>
#include <string>
#include <getopt.h>
#include "individual/individualFactory.h"


#define DEFAULT_GENERATIONS 500
#define DEFAULT_POPULATION_SIZE 50
#define DEFAULT_MUTATION_RATE 0.01


using namespace std;


void help() {
    cout << "Help" << endl;
}


int main(int argc, char **argv) {
    int generations = DEFAULT_GENERATIONS;
    int populationSize = DEFAULT_POPULATION_SIZE;
    double mutationRate = DEFAULT_MUTATION_RATE;

    string inputFilename;
    string outputFilename;

    int option;
    while ((option = getopt(argc, argv, "hf:o:")) != -1) {
        switch (option) {
            case 'h':
                help();
                return 0;
                break;

            case 'f':
                inputFilename = optarg;
                break;
            
            case 'o':
                outputFilename = optarg;
                break;
            
            case '?':
                cerr << "Error: Unknown option: " << argv[optind - 1] << endl;
                help();
                return 1;
        }
    }

    if (inputFilename.empty() || outputFilename.empty()) {
        cerr << "Error: Input and output filenames must be specified." << endl;
        help();
        return 2;
    }

    cout << "input: " << inputFilename << endl;
    cout << "output: " << outputFilename << endl;

    IndividualFactory factory;
    factory.loadInputFromFile(inputFilename);

    InputData inputData = factory.getInputData();
    cout << inputData.constraints.max_width << endl;
    cout << inputData.constraints.max_height << endl;

    return 0;
}