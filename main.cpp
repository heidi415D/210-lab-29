#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cmath>
using namespace std;

// Loads particle names and inital positions from file
void loadParticleData(map<string, array<list<double>, 3>>& particles, string filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error opening file. Using mock data.." << endl;
        //mock entries
        particles["P1"][0].push_back(1.0);
        particles["P1"][1].push_back(0.0);
        particles["P1"][2].push_back(0.5);

        particles["P2"][0].push_back(-0.5);
        particles["P2"][1].push_back(0.8);
        particles["P2"][2].push_back(0.0);

        return;

    }

    // function to simulate vector field motion
    void simulate(map<string, array<list<double>,3>>& particles, int steps) {
    // NEEDTO: Implement full physics later
    for (int t = 1; t <= steps; ++t) {
        cout << "Simulating step " << t << "..." << endl;
        // Ex dummy output
    }
}

int main() {
    map<string, array<list<double>, 3>> particles;
    loadParticleData(particles);

    cout << "Initial State:" << endl;
    cout << "P1: (1.0, 0.0, 0.5)" << endl;

    simulate(particles, 25);

    cout << "Simulation complete (mockup)." << endl;
    return 0;
}


// include necessary headers for file handling, data structures

// define a function to load particle data from an external file
// parameters: map of particles, filename
// try to open the file
// if the file fails to open, print an error message
// otherwise read particle name and starting x, y, z coordinates
// insert those values into the map:
// key = particle name
// value = array of three lists for x, y, z coordinates
// close the file

// define a function to simulate motion in the vector field
// parameters: map of particles, number of time steps, time interval (Δt)
// for each time step:
// iterate through each particle in the map
// retrieve the last x, y, z position
// compute the vector field F(x, y, z) = (y, -x, z)
// update each position using:
// x_new = x + Fx * Δt
// y_new = y + Fy * Δt
// z_new = z + Fz * Δt
// print the new coordinates for this particle
// end particle loop
 // end time-step loop

// define a function to display current particle positions
// iterate through the map
// print each particle’s most recent x, y, z coordinates

// define the main function
// declar a map of particles, each with an array of three lists for x, y, z coordinates
// call the load function to read initial particle data from "field_data.txt"
// call the simulation function to update positions over 25 time periods
// display the final state of the system
// end of main function

        
    