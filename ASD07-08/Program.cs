using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ASD07_08
{
    class Program
    {
        static void Main(string[] args)
        {
            int v = 19;
            int[] dfs = { 0, 1, 10, 16, 2, 5, 9, 11, 12, 14, 17, 18, 3, 6, 13, 15, 4, 7, 8 };
            string[] city = { 
                "Kyiv", "Zhytomyr", "Novograd-Volynskyi", 
                "Rivne", "Luc'k", "Berdychiv",
                "Vinnitsya","Hmel'nickiy", "Ternopil'",
                "Shepetivka", "Bila Cerkva", "Uman'",
                "Cherkasi", "Cremenchuk", "Poltava", 
                "Kharkiv", "Pryluki", "Sumi", "Myrgorod"
            };
            int[] km = { 135, 80, 100, 68, 38, 73, 110, 104, 115, 78, 115, 146, 105, 181, 130, 128, 175, 109 };
            int[,] edges = new int[v, v];
            bool[] visited = new bool[v];
            edges[0, 1] = 1; 
            edges[1, 2] = 1; 
            edges[2, 3] = 1; 
            edges[3, 4] = 1; 
            edges[1, 5] = 1; 
            edges[5, 6] = 1; 
            edges[6, 7] = 1;
            edges[7, 8] = 1; 
            edges[1, 9] = 1; 
            edges[0, 10] = 1;
            edges[10, 11] = 1;
            edges[10, 12] = 1; 
            edges[12, 13] = 1;
            edges[10, 14] = 1;
            edges[14, 15] = 1;
            edges[0, 16] = 1; 
            edges[16, 17] = 1;
            edges[16, 18] = 1;

            Console.WriteLine("DFS");
            for (int i = 0; i < v; i++)
            {
                if (!visited[i])
                    DFS(edges, v, visited, i, city);
            }
            for (int i = 0; i < v; i++)
            {
                visited[i] = false;
            }
            Console.WriteLine();
            Console.WriteLine("BFS");
            for (int i = 0; i < v; i++)
            {
                if (!visited[i])
                    BFS(edges, v, visited, i, dfs[i], city);
            }

            Console.WriteLine($"\nAll possible roots:");
            Console.WriteLine($"Kiyv - Zhytomyr: {km[0]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Novograd-Volynskiy: {km[0] + km[1]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Novograd-Volynskiy - Rivne: {km[0] + km[1] + km[2]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Novograd-Volynskiy - Rivne - Luc'k: {km[0] + km[1] + km[2] + km[3]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Berdychiv: {km[0] + km[4]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Berdychiv - Vinnytsya: {km[0] + km[4] + km[5]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Berdychiv - Vinnytsya - Khmel'nitskiy: {km[0] + km[4] + km[5] + km[6]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Berdychiv - Vinnytsya - Khmel'nitskiy - Ternopil': {km[0] + km[4] + km[5] + km[6] + km[7]}");
            Console.WriteLine($"Kiyv - Zhytomyr - Shepetivka: {km[0] + km[8]}");
            Console.WriteLine($"Kiyv - Bila Cerkva - Uman': {km[9] + km[10]}");
            Console.WriteLine($"Kiyv - Bila Cerkva - Cherkasy - Kremenchuk: {km[9] + km[11] + km[12]}");
            Console.WriteLine($"Kiyv - Bila Cerkva - Poltava - Kharkiv: {km[9] + km[13] + km[14]}");
            Console.WriteLine($"Kiyv - Pryluki - Sumi: {km[15] + km[16]}");
            Console.WriteLine($"Kiyv - Pryluki - Myrgorod: {km[15] + km[17]}");
        }
        static void DFS(int[,] edges, int v, bool[] visited, int si, string[] city)
        {
            visited[si] = true;
            Console.WriteLine(city[si] + " ");
            for (int i = 0; i < v; i++)
            {
                if (i == si)
                    continue;
                if (!visited[i] && edges[si, i] == 1)
                {
                    DFS(edges, v, visited, i, city);
                }
            }
        }
        static void BFS(int[,] edges, int v, bool[] visited, int j, int si, string[] city)
        {
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(si);
            visited[si] = true;
            while (queue.Count != 0)
            {
                int currentVertex = queue.Dequeue();
                Console.WriteLine(city[currentVertex] + " ");
                for (int i = 0; i < v; i++)
                {
                    if (i == j)
                        continue;
                    if (!visited[i] && edges[currentVertex, i] == 1)
                    {
                        queue.Enqueue(i);
                        visited[i] = true;
                    }
                }
            }
        }

    }
}



