#include <vector>
#include <cstdio>
#include <queue>
#include <array>

struct Node
{
    int id;
    bool visited;
    std::vector<Node*> connected;
    Node* previous;
};

const int nodeNumber = 13;
std::array<Node, nodeNumber> nodes;

void Solve(Node* start)
{
    std::queue<Node*> queue;
    queue.push(start);
    
    start->visited = true;
    
    while (!queue.empty())
    {
        Node* node = queue.front();
        queue.pop();
        
        for (int next = 0; next < node->connected.size(); next++)
        {
            if (!node->connected[next]->visited)
            {
                queue.push(node->connected[next]);
                node->connected[next]->visited = true;
                printf("visited node %d\n", node->connected[next]->id);
                node->connected[next]->previous = node;
            }
        }
    }
}

std::vector<Node*> ReconstructPath(Node* start, Node* end)
{
    Node* node = end;
    sxtd::vector<Node*> path;
    
    while (true)
    {
        path.push_back(node);
        if (node == start)
        {
            break;
        }
        node = node->previous;
    }
    
    std::vector<Node*> pathReversed;
    
    for (int i = path.size() - 1; i >= 0; i--)
    {
        pathReversed.push_back(path[i]);
    }
    
    return pathReversed;
}

void BFS(Node* start, Node* end)
{
    Solve(start);
    std::vector<Node*> path = ReconstructPath(start, end);
    
    printf("\n\npath:\n\n");
    
    for (int i = 0; i < path.size(); i++)
    {
        printf("struct Node\n");
        printf("{\n");
        printf("    int id = %d;\n", path[i]->id);
        if (path[i]->visited)
        {
            printf("    bool visited = true;\n");
        }
        else
        {
            printf("    bool visited = false;\n");
        }
        printf("    std::vector<Node*> connected; // Obviously I'm not going to print what this equals\n");
        printf("    Node* previous = %p;\n", path[i]->previous);
        
        printf("}\n");
    }
}

int main()
{
    nodes[0].id = 0;
    nodes[0].connected.push_back(&nodes[9]);
    nodes[0].connected.push_back(&nodes[11]);
    
    nodes[9].id = 9;
    nodes[9].connected.push_back(&nodes[0]);
    nodes[9].connected.push_back(&nodes[10]);
    nodes[9].connected.push_back(&nodes[8]);
    
    nodes[11].id = 11;
    nodes[11].connected.push_back(&nodes[0]);
    nodes[11].connected.push_back(&nodes[7]);
    
    nodes[7].id = 7;
    nodes[7].connected.push_back(&nodes[0]);
    nodes[7].connected.push_back(&nodes[11]);
    nodes[7].connected.push_back(&nodes[6]);
    
    nodes[6].id = 6;
    nodes[6].connected.push_back(&nodes[7]);
    nodes[6].connected.push_back(&nodes[5]);
    
    nodes[5].id = 5;
    nodes[5].connected.push_back(&nodes[6]);
    
    nodes[10].id = 10;
    nodes[10].connected.push_back(&nodes[1]);
    nodes[10].connected.push_back(&nodes[9]);
    
    nodes[1].id = 1;
    nodes[1].connected.push_back(&nodes[10]);
    nodes[1].connected.push_back(&nodes[8]);
    
    nodes[8].id = 8;
    nodes[8].connected.push_back(&nodes[12]);
    nodes[8].connected.push_back(&nodes[1]);
    nodes[8].connected.push_back(&nodes[9]);
    
    nodes[12].id = 12;
    nodes[12].connected.push_back(&nodes[8]);
    nodes[12].connected.push_back(&nodes[2]);
    
    nodes[2].id = 2;
    nodes[2].connected.push_back(&nodes[12]);
    nodes[2].connected.push_back(&nodes[3]);
    
    nodes[3].id = 3;
    nodes[3].connected.push_back(&nodes[2]);
    nodes[3].connected.push_back(&nodes[4]);
    nodes[3].connected.push_back(&nodes[7]);
    
    nodes[7].id = 0;
    nodes[7].connected.push_back(&nodes[3]);
    nodes[7].connected.push_back(&nodes[6]);
    nodes[7].connected.push_back(&nodes[0]);
    nodes[7].connected.push_back(&nodes[11]);
    
    nodes[4].id = 4;
    nodes[4].connected.push_back(&nodes[3]);
    
    BFS(&nodes[0], &nodes[12]);
    
    return 0;
}

