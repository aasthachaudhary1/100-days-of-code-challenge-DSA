#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_LEN 20
#define MAX_CHARS 26

char words[MAX_WORDS][MAX_LEN];
int num_words;

typedef struct {
    int head[MAX_CHARS];
    int next[256];
    char to[256];
    int total_edges;
} Graph;

Graph graph;
int indegree[MAX_CHARS];
bool used_char[MAX_CHARS];
char result[MAX_CHARS + 1];
int result_len;
bool is_valid;

void init_graph() {
    graph.total_edges = 0;
    memset(graph.head, -1, sizeof(graph.head));
    memset(indegree, 0, sizeof(indegree));
    memset(used_char, 0, sizeof(used_char));
    result_len = 0;
    is_valid = true;
}

void add_edge(char u, char v) {
    graph.to[graph.total_edges] = v;
    graph.next[graph.total_edges] = graph.head[u - 'a'];
    graph.head[u - 'a'] = graph.total_edges;
    graph.total_edges++;
}

void build_graph() {
    init_graph();
    for (int i = 0; i < num_words - 1 && is_valid; ++i) {
        int len1 = strlen(words[i]);
        int len2 = strlen(words[i + 1]);
        int min_len = len1 < len2 ? len1 : len2;
        
        bool found_diff = false;
        for (int k = 0; k < min_len; ++k) {
            if (words[i][k] != words[i + 1][k]) {
                add_edge(words[i][k], words[i + 1][k]);
                used_char[words[i][k] - 'a'] = true;
                used_char[words[i + 1][k] - 'a'] = true;
                found_diff = true;
                break;
            }
        }
        if (!found_diff && len1 > len2) {
            is_valid = false;
        }
    }
}

void compute_indegrees() {
    for (int u = 0; u < MAX_CHARS; ++u) {
        if (used_char[u]) {
            for (int eid = graph.head[u]; eid != -1; eid = graph.next[eid]) {
                indegree[graph.to[eid] - 'a']++;
            }
        }
    }
}

bool topological_sort() {
    int queue[MAX_CHARS];
    int front = 0, rear = 0;
    int processed = 0;

    for (int i = 0; i < MAX_CHARS; ++i) {
        if (used_char[i] && indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        result[result_len++] = 'a' + u;

        for (int eid = graph.head[u]; eid != -1; eid = graph.next[eid]) {
            int v = graph.to[eid] - 'a';
            indegree[v]--;
            if (indegree[v] == 0) {
                queue[rear++] = v;
            }
        }
        processed++;
    }

    int total_used = 0;
    for (int i = 0; i < MAX_CHARS; ++i) {
        if (used_char[i]) total_used++;
    }
    return processed == total_used;
}

char* findOrder(char* words_list[], int wordsCount) {
    num_words = wordsCount;
    for (int i = 0; i < wordsCount; ++i) {
        strcpy(words[i], words_list[i]);
    }
    
    build_graph();
    if (!is_valid) {
        result[0] = '\0';
        return result;
    }
    
    compute_indegrees();
    if (topological_sort()) {
        result[result_len] = '\0';
    } else {
        result[0] = '\0';
    }
    return result;
}
