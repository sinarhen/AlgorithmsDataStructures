
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    int isVisited;
} Node;

typedef struct Queue {
    int front, rear;
    unsigned capacity;
    Node* array;
} Queue;

typedef struct NodeRelation {
    Node* from;
    Node* to;
} NodeRelation;

typedef struct Graph {
    Node* vertices;
    NodeRelation* relations;
    int verticesCount;
    int relationsCount;
} Graph;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (Node*) malloc(queue->capacity * sizeof(Node));
    return queue;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == -1;
}

int isQueueFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

void enqueue(Queue* queue, Node item) {
    if (isQueueFull(queue)) {
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->array[++queue->rear] = item;
}

Node dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        Node emptyNode;
        emptyNode.data = -1;
        return emptyNode;
    }
    Node item = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return item;
}

Graph* createGraph(int verticesCount) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->vertices = (Node*) malloc(verticesCount * sizeof(Node));
    graph->relations = (NodeRelation*) malloc (sizeof(NodeRelation) * verticesCount);
    graph->verticesCount = verticesCount;
    graph->relationsCount = 0;
    return graph;
}

void addVertex(Graph* graph, int index, int data) {
    if (index >= graph->verticesCount) {
        return;
    }
    graph->vertices[index].data = data;
    graph->vertices[index].isVisited = 0;
}

void addRelation(Graph* graph, Node* from, Node* to) {
    NodeRelation relation;
    relation.from = from;
    relation.to = to;
    graph->relations[graph->relationsCount].from = from;
    graph->relations[graph->verticesCount].to = to;
    graph->verticesCount++;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->verticesCount; i++) {
        printf("Vertex: %d\n", graph->vertices[i].data);
    }
    for (int i = 0; i < graph->verticesCount; i++) {
        printf("Relation: %d -> %d\n", graph->relations[i].from->data, graph->relations[i].to->data);
    }
}

void bfs(Graph* graph, Node* start) {
    Queue* queue = createQueue(graph->verticesCount);
    enqueue(queue, *start);
    start->isVisited = 1;
    while (!isQueueEmpty(queue)) {
        Node current = dequeue(queue);
        printf("Visited: %d\n", current.data);
        for (int i = 0; i < graph->verticesCount; i++) {
            if (graph->relations[i].from->data == current.data && graph->relations[i].to->isVisited == 0) {
                enqueue(queue, *graph->relations[i].to);
                graph->relations[i].to->isVisited = 1;
            }
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add vertices
    for (int i = 0; i < 5; i++) {
        addVertex(graph, i, i);
    }

    // Add relations
    addRelation(graph, &graph->vertices[0], &graph->vertices[1]);
    addRelation(graph, &graph->vertices[0], &graph->vertices[2]);
    addRelation(graph, &graph->vertices[1], &graph->vertices[3]);
    addRelation(graph, &graph->vertices[2], &graph->vertices[4]);

    // Print the graph
    printGraph(graph);

    // Perform BFS
    printf("Performing BFS...\n");
    bfs(graph, &graph->vertices[0]);

    return 0;
}