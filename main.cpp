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
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }
        string name;
        double x, y, z;
        while (infile >> name >> x >> y >> z) {
            particles[name][0].push_back(x);
            particles[name][1].push_back(y);
            particles[name][2].push_back(z);
        }
        infile.close();
        }


    // Display current particle data
    void displayParticles(const map<string, array<list<double>, 3>>& particles) {
        for (const auto& pair : particles) {
            cout << p.first << ": ("
                 << p.second[0].back() << ", "
                 << p.second[1].back() << ", "
                 << p.second[2].back() << ")" << endl;
            }
        }

// simple timestep update - not done yet
    void simulateVectorField(map<string, array<list<double>,3>>& particles, int steps, double dt) {
        for (int t = 1; t <= steps; ++t) {}
            for (auto& p : particles) {
                double x = p.second[0].back();
                double y = p.second[1].back();
                double z = p.second[2].back();

                double Fx = -y;
                double Fy = x;
                double Fz = z;

                //basic rule for alpha version
                double x_new = x + y * dt;
                double y_new = y - x * dt;
                double z_new = z + z * dt;

                p.second[0].push_back(x_new);
                p.second[1].push_back(y_new);
                p.second[2].push_back(z_new);
            }
    }

    int main() {
        map<string, array<list<double>, 3>> particles;
        loadParticleData(particles, "field_data.txt");

        cout << "Initial State:\n";
        displayParticles(particles);

        simulateVectorField(particles, 5, 0.1); 
        cout << "\nAfter Simulation:\n";
        displayParticles(particles);

        cout << "Simulation complete (mockup)." << endl;
    
}




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

        
    