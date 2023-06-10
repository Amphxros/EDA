

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//O(log(n))
void crossG(const std::vector<int>& v, const std::vector<int>& w, const int N,
    const int ini, const int fin,
    int& x, int& y)
{
    
    if ((fin - ini) == 2) // Basis. One segment
    {
        if (v[ini] > w[ini]) { 
            x = ini - 1;
            y = ini; 
            return; 
        } 
        // previous segment
        if (v[ini] == w[ini]) {
            x = ini;
            y = ini + 1;
            return;
        }
        if (v[ini] < w[ini])
        {
            if (v[ini + 1] > w[ini + 1]) { x = ini; y = ini + 1; return; } // crossed 
            if (v[ini + 1] <= w[ini + 1]) { x = ini + 1; y = ini + 2; return; } // next segment		
        }
    }
    // size > 2
    int mit = (ini + fin) / 2;
    if (v[mit] == w[mit]) {
        x = mit;
        y = mit + 1;
        return; 
    }
    if (v[mit] > w[mit]) {
        crossG(v, w, N, ini, mit + 1, x, y); 
        return; 
    } // an eye!!, we must grab h as border!
    if (v[mit] < w[mit]) { 
        crossG(v, w, N, mit, fin, x, y);
        return; 
    }
}

/*
  P : (N-0)>1 strictInc(V[0..N)) and   strictDec(W[0..N))
  Q : [n,m) contains L(V) \cap L(W)
*/
void cross(const std::vector<int>& v, const std::vector<int>& w, const int N, int& x, int& y)
{
    return crossG(v, w, N, 0, N, x, y);
}



int main(int argc, char* args[])
{
    int N;
    int x, y;
    for (std::cin >> N; N; std::cin >> N)
    {
        std::vector<int>v(N);
        std::vector<int>w(N);
        for (int i = 0; i < N; i++)
            std::cin >> v[i];
        for (int i = 0; i < N; i++) 
            std::cin >> w[i];
        cross(v, w, N, x, y);
        std::cout << x << " " << y << "\n";
    }
    return 0;
}


/*

5
1 3 4 7 8
8 7 4 2 1
2 3
6
-5 -3 -1 0 4 7
9 6 5 2 1 0

3 4
6
1 3 4 5 7 8
-1 -2 -4 -5 -7 -8
-1 0
6
1 3 4 5 7 8
17 14 12 11 9 8
5 6
0



*/
