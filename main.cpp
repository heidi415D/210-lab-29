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
        int count = 0;

        for (const auto& p : particles) {
            cout << left << setw(6) << p.first << ": ("
                 << setw(8) << p.second[0].back() << ", "
                 << setw(8) << p.second[1].back() << ", "
                 << setw(8) << p.second[2].back() << ")";
            count++;
                 if (count % 3 == 0) // 3 per line for grid output
                 cout << "\n"; 
            }
            cout << "\n--------------------------------\n";
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
                double Fz = sin(z);

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

        if (particles.empty()) {
            cerr << "No particle data loaded. Exiting." << endl;
            return 1;
        }

        cout << "Initial State:\n";
        displayParticles(particles);

        // 25 time steps with dt = 0.1
        simulateVectorField(particles, 25, 0.1); 

        cout << "\nAfter Simulation:\n";
        displayParticles(particles);

        cout << "\nSimulating vector field...\n";
        cout << left << setw(30) << "Total Particles simulated:" << particles.size() << "\n";
        cout << left << setw(30) << "Time steps completed:" << 25 << "\n";
        cout << "----------------------------------------\n";
        cout << "Simulation complete.\n";

        return 0;
    
}



        
    