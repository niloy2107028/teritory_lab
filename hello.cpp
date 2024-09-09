#include <iostream>
#include <vector>
#include <limits>

//Bellmen_algorithm_for_finding_minimum_distance_among_vertices_in_a_graph_if_negative_cycle_is_not_present_or_vise_versa

//input containing negative cycle: 5 5 0 1 1 1 2 -2 2 3 -5 3 1 1 3 4 1
//input containing no negative cycle: 5 5 0 1 1 1 2 5 2 3 4 3 1 1 3 4 1

using namespace std;

struct edges
{
    int source;
    int destination;
    int weight;
};

int no_of_edges = 0;

class Graph
{
public:
    vector<vector<pair<int, int>>> graph;
    vector<edges> edge_arr;
    int no_of_vertices = 0;

    Graph(int n, int e)
    {
        no_of_vertices = n;
        graph.resize(no_of_vertices);
        edge_arr.reserve(e);
    }

    void Add_edges(int s, int d, int w)
    {
        edge_arr.push_back({s,d,w});
        graph[s].emplace_back(w, d);
    }
    void Display_graph()
    {
        cout << endl
             << "Displaying the graph : " << endl;
        for (int i = 0; i < graph.size(); i++)
        {
            cout << "Node (" << i << ") : ";
            for (const auto &p : graph[i])
            {
                cout << "..." << p.first << "...> (" << p.second << ")";
            }
            cout << endl;
        }

        cout << endl
             << "Displaying the edges : " << endl;
        for (int i = 0; i < edge_arr.size(); i++)
        {
            cout<<edge_arr[i].source<<"..."<<edge_arr[i].weight<<"...>"<<edge_arr[i].destination<<endl;
        }
        cout<<endl;
    }

    void Bellman_algorithm(int source)
    {
        vector <int> distance(no_of_vertices,numeric_limits<int>::max());
        distance[source]=0;

        for (int i = 0; i < no_of_vertices - 1; i++){

        for (const auto &edge:edge_arr)
        {
            int s=edge.source;
            int d=edge.destination;
            int w=edge.weight;
            if(distance[s]!=numeric_limits<int>::max()&&distance[s]+w<distance[d]){
                distance[d]=distance[s]+w;
            }
        }
        }

        //negative cycle ase kina

        int negative_cycle=0;

        for (const auto &edge:edge_arr)
        {
                        int s=edge.source;
            int d=edge.destination;
            int w=edge.weight;
            if(distance[s]!=numeric_limits<int>::max()&&distance[s]+w<distance[d]){
                cout<<"Graph has a negative-weight cycle"<<endl;
                cout<<"So minimum distance can't be found !"<<endl;
                negative_cycle=1;
                break;
            }
        }

        if(negative_cycle==0){
            cout<<"Printing the distance as there is no negative cycle "<<endl;
            for (int i = 0; i < no_of_vertices; i++)
            {
                cout<<"Distance of "<<i<<" is : "<<distance[i]<<endl;
            }
            
        }

        

        return ;
        
        
    }
};

int main()

{

    int n;
    cin >> n;


    int no_of_edges;
    cin >> no_of_edges;
    Graph g(n,no_of_edges);

    int source;
    int weight;
    int destination;

    for (int i = 0; i < no_of_edges; i++)
    {
        cin >> source >> destination >> weight;
        g.Add_edges(source, destination, weight);
    }

    g.Display_graph();

    g.Bellman_algorithm(0); 

    // cout << endl << "well termination" << endl;

    return 0;
}


