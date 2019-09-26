#include <iostream>
#include <iostream>
#include <exception>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
#include "atom.h"

using namespace std;
const double PI = 3.141592653589793;

class System{

    public:

        double dfactorial(int ,int );
        void convert_to_spherical_coordinates(double , double , double , double &, double &, double &);
        double PLM(int, int, double);
        void YLM(int , int , double , double , double &, double &);
        void QLM(int ,int ,double ,double ,double &, double & );
        void get_all_neighbors_normal();
        //helper functions
        //void process_neighbor_noincrement(int, int);
        void process_neighbor(int, int);
        //new version only needs prefactor - which is a safe cutoff
        int get_all_neighbors_sann(double);
        int get_all_neighbors_adaptive(double, int, double);

        void get_all_neighbors_voronoi();
        void reset_all_neighbors();
        void calculate_complexQLM_6();
        double get_number_from_bond(int,int);
        double get_number_from_bond(Atom ,Atom );
        void calculate_frenkel_numbers();
        double get_abs_distance(int,int,double&,double&,double&);
        double get_abs_distance(Atom , Atom );
        System();
        ~System();
        vector<int> get_indicators();
        void set_indicators(vector<int>);

        //Atom* atoms;
        vector<Atom> atoms;

        void read_particle_file(string);
        //void read_particle_instance(int,int);
        int calculate_nucsize();	//variant of function above
        int cluster_criteria(int,int );
        void find_solid_atoms();
        void find_clusters();
        void harvest_cluster(const int, const int);
        void find_clusters_recursive();
        void harvest_cluster_old(const int, const int);
        void find_clusters_recursive_old();
        int largest_cluster();
        void set_nucsize_parameters(int,double,double);
        //void set_inputfile(string);
        void set_neighbordistance(double);
        void assign_particles( vector<Atom>, vector<vector<double>>);
        void reassign_particles( vector<Atom>, vector<vector<double>>);
        void assign_triclinic_params(vector<vector<double>>, vector<vector<double>>);
        vector<vector<double>> get_triclinic_params();
        void get_largest_cluster_atoms();

        //average volumes
        void find_average_volume();
        //functions to set the list of reqd qs
        //again, error checking would be amazing here.
        void set_reqd_qs(vector<int>);
        void set_reqd_aqs(vector<int>);
        void calculate_q(vector <int>);
        void calculate_aq(vector <int>);
        int *reqdqs;
        int lenqs;
        int *reqdaqs;
        int lenaqs;
        //old params
        int nop;
        int baseunit;
        int minfrenkel;
        double boxx, boxy, boxz;
        //array for box
        double boxdims[3][2];
        string inputfile;
        vector<double> get_pairdistances();
        //power of face area weighting
        int alpha;
        void salpha(int);
        //indicator function - 1 if voronoi method is used
        //will be reset if any other method is used
        int voronoiused;
        //face cutoff
        double face_cutoff;
        void set_face_cutoff(double);

        double neighbordistance;

        double threshold;
        double avgthreshold;
        int maxclusterid;

        double rot[3][3];
        double rotinv[3][3];
        int triclinic;

        //variables for a filter
        int filter;
        void sfilter(int);
        //int apply_filter(int, int);

        //some access functions for system
        Atom gatom(int);
        void satom(Atom);
        int glargestclusterid();
        int gnop();
        vector<Atom> gallatoms();
        vector<double> gqvals(int qq);
        vector<double> gaqvals(int qq);
        vector<int> rq_backup;
        vector<double> gbox();
        vector<vector<double>> gboxvecs();
        void sbox(vector<vector<double>>);
        vector<double> gboxdims();

        //system flags
        int neighborsfound;
        int qsfound;
        int fileread;

};
