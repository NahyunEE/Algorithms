#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int node;   
    int road;   
};

int main() {
    int area_num;   
    int user_range; 
    int road_num;   

    cin >> area_num >> user_range >> road_num;

    vector<int> area_item(area_num, 0); 
    vector<vector<int>> vec(area_num, vector<int>(area_num, 0)); 
    vector<int> max_item(area_num, 0); 

    queue<int> temp_max;

  
    for (int i = 0; i < area_num; ++i) {
        cin >> area_item[i];
    }

   
    for (int k = 0; k < road_num; ++k) {
        int temp_x, temp_y, weight;
        cin >> temp_x >> temp_y >> weight;

        vec[temp_x - 1][temp_y - 1] = weight;
        vec[temp_y - 1][temp_x - 1] = weight;

        // 자신에 대해서는 0으로 초기화



    }

   
    for (int i = 0; i < area_num; ++i) {
        queue<Node> q;
        vector<bool> visited(area_num, false);
        int total_items = 0;

       
        q.push({ i, 0 });
        visited[i] = true;
        total_items += area_item[i];

       
        while (!q.empty()) {
            Node current = q.front();
            q.pop();

            for (int k = 0; k < area_num; ++k) {
                if (vec[current.node][k] != 0 && !visited[k]) {
                    //int new_distance = current.road + vec[current.node][k];

                    if (vec[current.node][k] <= user_range) {
                        visited[k] = true;
                        total_items += area_item[k]; 
                        q.push({ k, vec[current.node][k] });
                    }


                }
            }
        }

        
        max_item[i] = total_items;
    }

    
    sort(max_item.begin(), max_item.end());

    cout<< max_item[area_num-1] << endl;

    return 0;
}
