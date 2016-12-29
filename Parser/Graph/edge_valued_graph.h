//
// Created by Alexander Robau on 12/17/16.
//

#ifndef PARSER_EDGE_VALUED_GRAPH_H
#define PARSER_EDGE_VALUED_GRAPH_H

#include <memory>
#include <vector>
#include <stack>
#include <string>
#include <functional>

template<typename N, typename E>
class EdgeValuedGraph {
public:
    typedef const std::function<bool(const N&, const N&)>& NodeEqualityFunction;

    // MARK: PUBLIC CLASSES

    class Traverser {
    public:
        void TraverseVia(E value) {
            nodes_visited_.push(nodes_visited_.top().NodeViaEdgeValue(value));
        }

        void TraverseBack() {
            nodes_visited_.pop();
        }

        N& CurrentNodeValue() {
            return nodes_visited_.top().value;
        }
    private:
        std::stack<GraphNode&> nodes_visited_;
    };

    // MARK: CONSTRUCTORS

    EdgeValuedGraph() : nodes_({}), edges_({}), node_equals_(nullptr) {}

    EdgeValuedGraph(const std::vector<N>& node_values) : edges_({}), node_equals_(nullptr) {
        for (auto iter = node_values.begin(); iter != node_values.end(); ++iter) {
            nodes_.push_back(new GraphNode(*iter));
        }
    }

    EdgeValuedGraph(NodeEqualityFunction node_equals)
            : nodes_({}), edges_({}), node_equals_(new NodeEqualityFunction(node_equals)) {}

    EdgeValuedGraph(const std::vector<N>& node_values, NodeEqualityFunction node_equals)
            : edges_({}), node_equals_(new NodeEqualityFunction(node_equals)) {
        for (auto iter = node_values.begin(); iter != node_values.end(); ++iter) {
            nodes_.push_back(new GraphNode(*iter));
        }
    }

    // MARK: Public methods

    Traverser TraverserForNode(const N& node_value) {

    }

    std::size_t AddNode(const N& node_value) {
        nodes_.push_back(new GraphNode(node_value));
        return nodes_.size() - 1;  // Return the location of the node
    }

    void RemoveNode(int location) {
        nodes_.erase(nodes_.begin() + location);
    }

    void RemoveNode(const N& node_value) {
        if (node_equals_ == nullptr) {
            throw std::exception();
        }
        else {
            RemoveNode(node_value, *node_equals_);
        }
    }

    void RemoveNode(const N& node_value, NodeEqualityFunction node_equals) {
        for (auto iter = nodes_.begin(); iter != nodes_.end(); ) {
            if (node_equals((*iter)->value, node_value)) {
                nodes_.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    N& GetNode(int location) {
        return nodes_[location]->value;
    }

    const N& GetNode(int location) const {
        return nodes_[location]->value;
    }

    std::vector<E> FindEdgeValues(int current_node) const {
        GraphNode* node = nodes_[current_node].get();
        std::vector<E> edge_values = {};
        for (GraphEdge& edge : node->connected_edges) {
            edge_values.push_back(edge.edge_value);
        }
        return edge_values;
    }

    void ConnectNodes(int node_location_1, int node_location_2, E edge_value) {
        if (!NodeLocationInRange(node_location_1) && !NodeLocationInRange(node_location_2)) {
            throw std::out_of_range("Both node locations out of range");
        }
        else if (!NodeLocationInRange(node_location_1)) {
            throw std::out_of_range("Node location 1 out of range");
        }
        else if (!NodeLocationInRange(node_location_2)) {
            throw std::out_of_range("Node location 2 out of range");
        }
        GraphNode& graph_node_1 = *nodes_[node_location_1];
        GraphEdge& graph_node_2 = *nodes_[node_location_2];

        ConnectGraphNodes(graph_node_1, graph_node_2, edge_value);
    }

    void ConnectNodes(const N& node_1, const N& node_2) {
        if (node_equals_ == nullptr) {
            throw std::exception();
        }
        else {
            ConnectNodes(node_1, node_2, *node_equals_);
        }
    }

    void ConnectNodes(const N& node_1, const N& node_2, E edge_value, NodeEqualityFunction nodes_equal) {
        GraphNode* graph_node_1 = FindGraphNodeForNodeValue(node_1, nodes_equal);
        GraphNode* graph_node_2 = FindGraphNodeForNodeValue(node_2, nodes_equal);

        // Check if the nodes were found and throw appropriate exceptions
        if (graph_node_1 == nullptr && graph_node_2 == nullptr) {
            throw std::invalid_argument("Could not find either node");
        }
        else if (graph_node_1 == nullptr) {
            throw std::invalid_argument("Could not find first node in arguments");
        }
        else if (graph_node_2 == nullptr) {
            throw std::invalid_argument("Could not find second node in arguments");
        }

        ConnectGraphNodes(*graph_node_1, *graph_node_2, edge_value);
    }

    void RemoveConnection(const N& node_1, const N& node_2, E edge_value) {
        if (node_equals_ == nullptr) {
            throw std::exception();
        }
        else {
            RemoveConnection(node_1, node_2, edge_value, *node_equals_);
        }
    }

    void RemoveConnection(const N& node_1, const N& node_2, E edge_value, NodeEqualityFunction nodes_equal) {
        GraphNode* graph_node_1 = FindGraphNodeForNodeValue(node_1, nodes_equal);
        GraphNode* graph_node_2 = FindGraphNodeForNodeValue(node_2, nodes_equal);

        // Check if the nodes were found and throw appropriate exceptions
        if (graph_node_1 == nullptr && graph_node_2 == nullptr) {
            throw std::invalid_argument("Could not find either node");
        }
        else if (graph_node_1 == nullptr) {
            throw std::invalid_argument("Could not find first node in arguments");
        }
        else if (graph_node_2 == nullptr) {
            throw std::invalid_argument("Could not find second node in arguments");
        }

        RemoveGraphNodeConnection(*graph_node_1, *graph_node_2, edge_value);
    }

    void RemoveConnection(int node_location_1, int node_location_2, E edge_value) {
        if (!NodeLocationInRange(node_location_1) && !NodeLocationInRange(node_location_2)) {
            throw std::out_of_range("Both node locations out of range");
        }
        else if (!NodeLocationInRange(node_location_1)) {
            throw std::out_of_range("Node location 1 out of range");
        }
        else if (!NodeLocationInRange(node_location_2)) {
            throw std::out_of_range("Node location 2 out of range");
        }
        GraphNode& graph_node_1 = *nodes_[node_location_1];
        GraphEdge& graph_node_2 = *nodes_[node_location_2];

        RemoveGraphNodeConnection(graph_node_1, graph_node_2, edge_value);
    }

    N& NodeConnected(const N& node, const E edge_value, NodeEqualityFunction nodes_equal) {
        for (const GraphNode& graph_node : nodes_) {
            if (nodes_equal(graph_node.value, node)) {
                return node.NodeViaEdgeValue(edge_value).value;
            }
        }
        throw std::out_of_range("Failed to find input node pointer in the graph.");
    }

    const N& NodeConnected(const N& node, const E edge_value, NodeEqualityFunction nodes_equal) const {
        for (const GraphNode& graph_node : nodes_) {
            if (nodes_equal(graph_node.value, node)) {
                return node.NodeViaEdgeValue(edge_value).value;
            }
        }
        throw std::out_of_range("Failed to find input node pointer in the graph.");
    }

    std::size_t Size() {
        return nodes_.size();
    }

private:

    // MARK: PRIVATE CLASSES

    class GraphEdge {
    public:
        GraphEdge(E edge_value, GraphNode& node_1, GraphNode& node_2)
                : edge_value(edge_value), node_1(node_1), node_2(node_2) {}

        E edge_value;           // The edge value
        GraphNode& node_1;      // Reference to the first node
        GraphNode& node_2;      // Reference to the second node

        // Get the other node in the edge given one of the nodes
        GraphNode& OtherNode(GraphNode& node) {
            if (&node == &node_1) {
                // The address of node is the same as the address of the node_1, return reference to node_2
                return node_2;
            }
            else if (&node == &node_2) {
                // The address of node is the same as the address of the node_2, return reference to node_1
                return node_1;
            }
            else {
                // Neither reference was the one we are looking for, throw an error
                throw std::invalid_argument("The given node is not in this edge");
            }
        }
    };

    class GraphNode {
    public:
        GraphNode(const N& val) : value(val), connected_edges({}) {}

        GraphNode& NodeViaEdgeValue(E edge_value) {
            for (GraphEdge& edge : connected_edges) {
                if (edge_value == edge.edge_value) {
                    return edge.OtherNode(*this);
                }
            }

            std::string err = "Failed to find an edge with desired edge value connecting input node to any other node.";
            throw std::invalid_argument(err);
        }


        void RemoveEdge(E edge_value, const GraphNode& other_node) {
            for (auto iter = connected_edges.begin(); iter != connected_edges.end(); ) {
                if (iter->get().edge_value == edge_value && &iter->get().OtherNode(*this) == &other_node) {
                    connected_edges.erase(iter);
                }
                else {
                    ++iter;
                }
            }
        }

        N value;
        std::vector<std::reference_wrapper<GraphEdge>> connected_edges;
    };

    // MARK: PRIVATE MEMBERS

    std::vector<std::unique_ptr<GraphNode>> nodes_;
    std::vector<std::unique_ptr<GraphEdge>> edges_;
    std::unique_ptr<NodeEqualityFunction> node_equals_;

    // MARK: PRIVATE FUNCTIONS

    // TODO: Refactor fo efficient finding (map?)
    GraphNode* FindGraphNodeForNodeValue(const N& node_value, NodeEqualityFunction nodes_equal) {
        // Find the associated graph node in the collection of nodes
        GraphNode* graph_node = nullptr;
        for (auto iter = nodes_.begin(); iter != nodes_.end(); ++iter) {
            if (nodes_equal((*iter)->value, node_value)) {
                graph_node = iter->get();
                break;
            }
        }

        return graph_node;
    }

    void ConnectGraphNodes(GraphNode& graph_node_1, GraphNode& graph_node_2, E edge_value) {
        // Add the newly created edge connection between the two nodes
        GraphEdge* new_edge = new GraphEdge(edge_value, graph_node_1, graph_node_2);
        edges_.push_back(new_edge);
        graph_node_1.connected_edges.push_back(*new_edge);
        graph_node_2.connected_edges.push_back(*new_edge);
    }

    void RemoveGraphNodeConnection(GraphNode& graph_node_1, GraphNode& graph_node_2, E edge_value) {
        // TODO refactor into separate methods
        graph_node_1.RemoveEdge(edge_value, graph_node_2);
        graph_node_2.RemoveEdge(edge_value, graph_node_1);

        for (auto iter = edges_.begin(); iter != edges_.end(); ) {
            if (&(*iter)->node_1 == &graph_node_1 && &(*iter)->node_2 == &graph_node_2 &&
                (*iter)->edge_value == edge_value) {
                edges_.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }

    bool NodeLocationInRange(int node_location) {
        return node_location > 0 && node_location < nodes_.size();
    }
};


#endif //PARSER_EDGE_VALUED_GRAPH_H
