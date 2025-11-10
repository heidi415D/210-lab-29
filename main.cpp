#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cmath>
#include <iomanip>
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
        cout << fixed << setprecision(2); // clean formatating
        
        for (const auto& p : particles) {
            cout << p.first << ": ("
                 << p.second[0].back() << ", "
                 << p.second[1].back() << ", "
                 << p.second[2].back() << ")" << endl;
            }
        }

// simulate particle movement in a simple 3D vector field
    void simulateVectorField(map<string, array<list<double>,3>>& particles, int steps, double dt) {
        for (int t = 1; t <= steps; ++t) {
            for (auto& p : particles) {
                double x = p.second[0].back();
                double y = p.second[1].back();
                double z = p.second[2].back();

                double Fx = y;
                double Fy = -x;
                double Fz = z;

                // basic rule 
                double x_new = x + Fx * dt;
                double y_new = y + Fy * dt;
                double z_new = z + Fz * dt;

                p.second[0].push_back(x_new);
                p.second[1].push_back(y_new);
                p.second[2].push_back(z_new);
            }
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



        
    